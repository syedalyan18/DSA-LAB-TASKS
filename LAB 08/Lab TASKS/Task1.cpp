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
    Node* insert(Node* root, int key) {
        if (!root) {
            return new Node(key);
        }
        
        if (key == root->val) {
            cout << "Duplicate roll number " << key << " ignored.\n";
            return root;
        }
        
        if (key > root->val) {
            root->right = insert(root->right, key);
        } else {
            root->left = insert(root->left, key);
        }
        return root;
    }

    bool search(Node* root, int key) {
        if (!root) {
            cout << "NOT FOUND\n";
            return false;
        }

        cout << root->val;

        if (root->val == key) {
            cout << " FOUND\n";
            return true;
        }

        cout << " -> "; 

        if (key > root->val) {
            return search(root->right, key);
        } else {
            return search(root->left, key);
        }
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

int main() {
    Node* root = NULL;
    BST tree;
    int choice, val;
    
    while (true) {
        cout << "\n--- FAST Karachi Admission Portal ---\n";
        cout << "1) Register applicant\n";
        cout << "2) Search applicant\n";
        cout << "3) Display sorted list\n";
        cout << "4) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter roll number to register: ";
                cin >> val;
                root = tree.insert(root, val);
                break;
            case 2:
                cout << "Enter roll number to search: ";
                cin >> val;
                cout << "Search " << val << " : ";
                tree.search(root, val);
                break;
            case 3:
                cout << "Sorted list : ";
                tree.inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "bye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again\n";
        }
    }
    return 0;
}
