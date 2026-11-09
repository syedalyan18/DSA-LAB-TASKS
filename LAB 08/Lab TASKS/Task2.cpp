#include <iostream>
using namespace std;
// Scenario
// A city hospital stores admitted patients in a BST ordered by Patient ID. When a patient is discharged, their
// record must be removed without breaking the BST property. After each discharge the ward manager wants
// to see the updated tree structure (pre-order) to confirm that nothing went wrong.
// Requirements
// • Implement findMin() and deleteNode() handling all three cases: leaf, one child, and two children
// (use the in-order successor).
// • Before each deletion, print which case applies: LEAF, ONE CHILD or TWO CHILDREN (replaced by
// successor X).
// • Print the pre-order and in-order traversals after every discharge. The in-order output must always
// remain sorted.
// • If the Patient ID does not exist, print Patient not found and leave the tree unchanged.
// • Bonus (+2, inside the 10): also implement deletion using the in-order predecessor and compare the
// resulting trees for the same input.
// Sample Test
// Admit (in order): 10 6 13 4 8 11 25 2 5 7 9 12 20
// Initial pre-order : 10 6 4 2 5 8 7 9 13 11 12 25 20
// Discharge 2 -> LEAF
// pre-order : 10 6 4 5 8 7 9 13 11 12 25 20
// Discharge 11 -> ONE CHILD
// pre-order : 10 6 4 5 8 7 9 13 12 25 20
// Discharge 6 -> TWO CHILDREN (replaced by successor 7)
// pre-order : 10 7 4 5 8 9 13 12 25 20
// in-order : 4 5 7 8 9 10 12 13 20 25
// Discharge 99 -> Patient not found
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
    Node* insert(Node* root, int key) {
        if (!root) {
            return new Node(key);
        }
        
        if (key == root->val) {
            cout << "Duplicate ID" << key << " ignored.\n";
            return root;
        }
        
        if (key > root->val) {
            root->right = insert(root->right, key);
        } else {
            root->left = insert(root->left, key);
        }
        return root;
    }
    Node* findMin(Node* root) {
        if (!root) return nullptr;
        while (root->left) {
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) {
            cout << "Discharge " << key << " -> Patient not found" << endl;
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            cout << "Discharge " << key;
            if (!root->left && !root->right) {
                cout << " -> LEAF" << endl;
                delete root;
                return nullptr;
            }
            if (!root->left || !root->right) {
                cout << " -> ONE CHILD" << endl;
                Node* child = root->left ? root->left : root->right;
                delete root;
                return child;
            }

            Node* successor = findMin(root->right);
            cout << " -> TWO CHILDREN (replaced by successor "
                 << successor->val << ")" << endl;
            root->val = successor->val;
            root->right = removeNode(root->right, successor->val);
        }
        return root;
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

private:
    Node* removeNode(Node* root, int key) {
        if (key < root->val) {
            root->left = removeNode(root->left, key);
        } else if (key > root->val) {
            root->right = removeNode(root->right, key);
        } else {
            if (!root->left) {
                Node* child = root->right;
                delete root;
                return child;
            }
            if (!root->right) {
                Node* child = root->left;
                delete root;
                return child;
            }
        }
        return root;
    }
};

int main() {
    Node* root = nullptr;
    BST tree;

    int patientIds[] = {10, 6, 13, 4, 8, 11, 25, 2, 5, 7, 9, 12, 20};
    for (int patientId : patientIds) {
        root = tree.insert(root, patientId);
    }

    int discharges[] = {2, 11, 6, 99};
    for (int patientId : discharges) {
        root = tree.deleteNode(root, patientId);
        cout << "pre-order: ";
        tree.preorder(root);
        cout << "\nin-order: ";
        tree.inorder(root);
        cout << "\n";
    }

    return 0;
}