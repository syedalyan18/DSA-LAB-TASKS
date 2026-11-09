#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    int visitedCount = 0;

    Node* insert(Node* root, int key) {
        if (!root) {
            return new Node(key);
        }
        
        if (key == root->val) {
            cout << "Duplicate prices" << key << " ignored.\n";
            return root;
        }
        
        if (key > root->val) {
            root->right = insert(root->right, key);
        } else {
            root->left = insert(root->left, key);
        }
        return root;
    }
    Node* findMin(Node* root){
        if(!root) return nullptr;
        while (root->left) {
            root = root->left;
        }
        return root;
    }
    Node* findMax(Node* root){
        if(!root) return nullptr;
        while (root->right) {
            root = root->right;
        }
        return root;
    }
    void rangeSearch(Node *root, int low,int high) {
        if (!root) {
            return;
        }
        visitedCount++;

        if (root->val > low) {
            rangeSearch(root->left, low, high);
        }
        if (root->val >= low && root->val <= high) {
            cout << root->val << " ";
        }
        if (root->val < high) {
            rangeSearch(root->right, low, high);
        }
    }

    Node* floorPrice(Node* root, int price) {
        Node* floor = nullptr;
        while (root) {
            if (root->val == price) {
                return root;
            }
            if (root->val < price) {
                floor = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
    }

    Node* ceilPrice(Node* root, int price) {
        Node* ceil = nullptr;
        while (root) {
            if (root->val == price) {
                return root;
            }
            if (root->val > price) {
                ceil = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ceil;
    }

    int totalNodes(Node* root) {
        if (!root) return 0;
        return 1 + totalNodes(root->left) + totalNodes(root->right);
    }
};

int main() {
    BST tree;
    Node* root = nullptr;
    int prices[] = {1500, 800, 2500, 500, 1000, 2000, 3500, 750, 1200, 3000};

    for (int price : prices) {
        root = tree.insert(root, price);
    }

    cout << "Range [1000, 2500] : ";
    tree.rangeSearch(root, 1000, 2500);
    cout << "\nVisited nodes: " << tree.visitedCount
         << " / " << tree.totalNodes(root) << "\n";

    cout << "Cheapest : " << tree.findMin(root)->val << "\n";
    cout << "Most expensive : " << tree.findMax(root)->val << "\n";

    Node* floor = tree.floorPrice(root, 1800);
    Node* ceil = tree.ceilPrice(root, 1800);
    cout << "Floor(1800) : " << (floor ? to_string(floor->val) : "None")
         << " Ceil(1800) : " << (ceil ? to_string(ceil->val) : "None") << "\n";

    floor = tree.floorPrice(root, 400);
    ceil = tree.ceilPrice(root, 3600);
    cout << "Floor(400) : " << (floor ? to_string(floor->val) : "None")
         << " Ceil(3600) : " << (ceil ? to_string(ceil->val) : "None") << "\n";

    return 0;
}