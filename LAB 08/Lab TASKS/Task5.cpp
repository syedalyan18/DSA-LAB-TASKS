#include <climits>
#include <iostream>
#include <string>

using namespace std;

struct Node {
	int account;
	Node* left;
	Node* right;

	Node(int value) : account(value), left(nullptr), right(nullptr) {}
};

bool isBST(Node* root, long long minVal, long long maxVal) {
	if (root == nullptr) {
		return true;
	}

	if (root->account <= minVal || root->account >= maxVal) {
		return false;
	}

	return isBST(root->left, minVal, root->account) &&
		   isBST(root->right, root->account, maxVal);
}

Node* inorderSuccessor(Node* root, int key) {
	Node* successor = nullptr;

	while (root != nullptr) {
		if (root->account > key) {
			successor = root;
			root = root->left;
		} else {
			root = root->right;
		}
	}

	return successor;
}

void kthSmallest(Node* root, int k, int& count, int& result) {
	if (root == nullptr || count >= k) {
		return;
	}

	kthSmallest(root->left, k, count, result);

	if (++count == k) {
		result = root->account;
		return;
	}

	kthSmallest(root->right, k, count, result);
}

int kthSmallest(Node* root, int k) {
	int count = 0;
	int result = -1;
	kthSmallest(root, k, count, result);
	return result;
}

void printSuccessor(Node* root, int key) {
	Node* successor = inorderSuccessor(root, key);
	cout << "Successor(" << key << ") = ";

	if (successor == nullptr) {
		cout << "None";
	} else {
		cout << successor->account;
	}

	cout << '\n';
}

void printKthSmallest(Node* root, int k) {
	int result = kthSmallest(root, k);
	string suffix = "th";
	if (k % 100 < 11 || k % 100 > 13) {
		if (k % 10 == 1) {
			suffix = "st";
		} else if (k % 10 == 2) {
			suffix = "nd";
		} else if (k % 10 == 3) {
			suffix = "rd";
		}
	}

	cout << k << suffix << " smallest = ";

	if (result == -1) {
		cout << "Out of range";
	} else {
		cout << result;
	}

	cout << '\n';
}

int main() {
	Node* treeA = new Node(50);
	treeA->left = new Node(30);
	treeA->right = new Node(70);
	treeA->left->left = new Node(20);
	treeA->left->right = new Node(40);
	treeA->right->left = new Node(60);
	treeA->right->right = new Node(80);

	Node* treeB = new Node(50);
	treeB->left = new Node(30);
	treeB->right = new Node(70);
	treeB->left->left = new Node(20);
	treeB->left->right = new Node(60);
	treeB->right->left = new Node(40);
	treeB->right->right = new Node(80);

	cout << "Tree A : "
		 << (isBST(treeA, LLONG_MIN, LLONG_MAX) ? "VALID BST" : "CORRUPTED")
		 << '\n';
	cout << "Tree B : "
		 << (isBST(treeB, LLONG_MIN, LLONG_MAX)
				 ? "VALID BST"
				 : "CORRUPTED (60 sits in the left subtree of 50 but is larger than 50)")
		 << '\n';

	if (isBST(treeA, LLONG_MIN, LLONG_MAX)) {
		printSuccessor(treeA, 40);
		printSuccessor(treeA, 60);
		printSuccessor(treeA, 30);
		printSuccessor(treeA, 80);
		printKthSmallest(treeA, 3);
		printKthSmallest(treeA, 7);
		printKthSmallest(treeA, 8);
	}

	return 0;
}
