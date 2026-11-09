#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
    int id;
    Node* left;
    Node* right;
    Node(int i){
        id = i;
        left = NULL;
        right = NULL;
    }
};
Node* createNode(int id){
    return new Node(id);
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->id << " ";
    inorder(root->right);
}
void preorder(Node* root){
    if(!root) return;
    cout << root->id << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->id << " ";
}
void levelorder(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->id << " ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return;
}
int height(Node* root){
    if(!root) return -1;
    return 1 + max(height(root->left),height(root->right));
}
int totalnode(Node* root){
    if(!root){
        return 0;
    }
    return 1 + totalnode(root->left) + totalnode(root->right);
}
int leaves(Node* root){
    if(!root) return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    return leaves(root->left) + leaves(root->right);
}
bool isFull(Node* root){
    if(!root){
        return true;
    }
    if((root->left == nullptr) != (root->right == nullptr)){
        return false;
    }
    return isFull(root->left) && isFull(root->right);
}
bool isComplete(Node* root){
    if(!root) return true;
    queue<Node*> q;
    q.push(root);
    bool flag = false;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == nullptr){
            flag = true;
        }else{
            if(flag){
                return false;
            }
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return true;
}
void printAnalysis(const char* chartName, Node* root){
    cout << chartName << "\n";
    cout << "Pre-order : ";
    preorder(root);
    cout << "\nIn-order : ";
    inorder(root);
    cout << "\nPost-order : ";
    postorder(root);
    cout << "\nLevel-order : ";
    levelorder(root);
    cout << "\nNodes: " << totalnode(root)
         << "\nLeaves: " << leaves(root)
         << "\nHeight: " << height(root)
         << "\nFull? " << (isFull(root) ? "Yes" : "No")
         << "\nComplete? " << (isComplete(root) ? "Yes" : "No")
         << "\n\n";
}

int main(){
    Node* chartA = createNode(1);
    chartA->left = createNode(2);
    chartA->right = createNode(3);
    chartA->left->left = createNode(4);
    chartA->left->right = createNode(5);
    chartA->right->left = createNode(6);

    Node* chartB = createNode(1);
    chartB->left = createNode(2);
    chartB->right = createNode(3);
    chartB->left->left = createNode(4);
    chartB->left->right = createNode(5);
    chartB->right->right = createNode(7);

    Node* chartC = createNode(1);
    chartC->left = createNode(2);
    chartC->right = createNode(3);
    chartC->left->left = createNode(4);
    chartC->left->right = createNode(5);
    chartC->right->left = createNode(6);
    chartC->right->right = createNode(7);

    printAnalysis("Chart A", chartA);
    printAnalysis("Chart B", chartB);
    printAnalysis("Chart C", chartC);

    return 0;
}