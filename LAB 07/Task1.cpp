
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// CREATE NODE

Node* createNode(int value)
{
    Node* newNode = new Node(value);
    return newNode;
}

// INSERTION

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// SEARCHING

bool search(Node* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// FIND MINIMUM

Node* findMin(Node* root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

// DELETION

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // CASE 1: NO LEFT CHILD

        if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // CASE 2: NO RIGHT CHILD

        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // CASE 3: TWO CHILDREN

        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// UPDATE

Node* update(Node* root, int oldValue, int newValue)
{
    if (!search(root, oldValue))
    {
        cout << "Student not found\n";
        return root;
    }

    if (search(root, newValue))
    {
        cout << "New ID already exists\n";
        return root;
    }

    root = deleteNode(root, oldValue);

    root = insert(root, newValue);

    return root;
}

// PREORDER

void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// INORDER

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// POSTORDER

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

// COUNT NODES

int countNodes(Node* root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

// MAIN

int main()
{
    Node* root = NULL;

    int choice, value, oldValue, newValue;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Delete";
        cout << "\n4. Update";
        cout << "\n5. Inorder";
        cout << "\n6. Preorder";
        cout << "\n7. Postorder";
        cout << "\n8. Count Nodes";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;

                root = insert(root, value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;

                if (search(root, value))
                    cout << "Found\n";
                else
                    cout << "Not Found\n";

                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;

                root = deleteNode(root, value);
                break;

            case 4:
                cout << "Enter old value: ";
                cin >> oldValue;

                cout << "Enter new value: ";
                cin >> newValue;

                root = update(root, oldValue, newValue);
                break;

            case 5:
                inorder(root);
                break;

            case 6:
                preorder(root);
                break;

            case 7:
                postorder(root);
                break;

            case 8:
                cout << countNodes(root);
                break;
        }

    } while (choice != 0);

    return 0;
}
