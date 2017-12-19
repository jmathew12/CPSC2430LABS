
// James Mathew
// Lab 3

struct Node
{
	int data;
	Node* left;
	Node* right;
};

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


bool insertData(Node*& root, int val);
void printInOrder(Node* root);
void printPreOrder(Node* root);
void printPostOrder(Node* root);
void deleteTree(Node*& root);

int main()
{
	Node* root = nullptr;
	srand(time(0));
	int val;
	for(int i = 0; i < 10; i++) {
		val = rand() % 10;
		// cout << "inserting " << val << endl;
		insertData(root, val);
		insertData(root, val + val);
	}
	cout << "Inorder" << endl;
	printInOrder(root);
	cout << "Preorder" << endl;
	printPreOrder(root);
	cout << "Postorder" << endl;
	printPostOrder(root);
	deleteTree(root);
	// if (root == nullptr) {
		// cout << "everything deleted" << endl;
	// }
	// cout << "After delete" << endl;
	// cout << "printing in order" << endl;
	// printInOrder(root);
	// cout << "printing in preorder" << endl;
	// printPreOrder(root);
	// cout << "printing in post order" << endl;
	// printPostOrder(root);
	
	return 0;
}

bool insertData(Node*& root, int val)
{
	if(root == nullptr) {
		Node* newBranch = new Node;
		newBranch->data = val;
		root = newBranch;
		// root->left = nullptr;
		// root->right = nullptr; // without these, still works, why?
	} else if (val > root->data) {
		insertData(root->right, val);
	} else if (val < root->data) {
		insertData(root->left, val);
	} else {
		return false;
	}
	return true;
}

void printInOrder(Node* root)
{
	if (root != nullptr) {
		printInOrder(root->left);
		cout << root->data << endl;
		printInOrder(root->right);
	}
}

void printPreOrder(Node* root)
{
	if (root != nullptr) {
		cout << root->data << endl;
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void printPostOrder(Node* root)
{
	if (root != nullptr) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->data << endl;
	}
}
void deleteTree(Node*& root)
{
	// if (root == nullptr) {
		
	// } else 
		if (root != nullptr && root->left == nullptr && root->right == nullptr) {
		// cout << "deleting " << root->data << " leaf" << endl;
		delete root;
		// cout << "after deleting " << root->data << " leaf" << endl;
	} else if (root != nullptr) {
		deleteTree(root->left);
		deleteTree(root->right);
		//cout << "deleting " << root->data << " branch" << endl;
		delete root;
		//cout << "after deleting " << root->data << " branch" << endl;
	}
}