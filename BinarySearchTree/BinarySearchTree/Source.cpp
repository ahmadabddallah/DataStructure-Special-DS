#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;

	Node(int value) {
		data = value;
		left = right = NULL;
	}


};
class BST {
public:
	Node* root;

	BST() {
		root = NULL;
	}

	Node* insert(Node* r, int item)
	{
		if (r == NULL) {
			Node* newnode = new Node(item);
			r = newnode;
		}
		else if (item < r->data) {
			r->left = insert(r->left, item);
		}
		else
			r->right = insert(r->right, item);

		return r;
	}
	void insert(int item)
	{
		root = insert(root, item);
	}


	void Preorder(Node* r)
	{ //root->left->right
		if (r == NULL) {
			return;
		}
		cout << r->data << "\t";
		Preorder(r->left);
		Preorder(r->right);

	}
	void Inorder(Node* r)
	{ //left->root->right
		if (r == NULL)
			return;
		Inorder(r->left);
		cout << r->data << "\t";
		Inorder(r->right);

	}
	void Postorder(Node* r)
	{ //left->right->root
		if (r == NULL)
			return;
		Inorder(r->left);
		Inorder(r->right);
		cout << r->data << "\t";


	}


	Node* Search(Node* r, int key) {

		if (r == NULL) {
			return NULL;
		}
		else if (r->data == key) {
			return r;
		}
		else if (key < r->data) {
			return Search(r->left, key);
		}
		else
			return Search(r->right, key);
	}
	bool Search(int key) {
		Node* result = Search(root, key);
		if (result == NULL) {
			return false;
		}
		else
			return true;
	}
	Node* Findmin(Node* r) {
		if (r == NULL) {
			return NULL;
		}
		else if (r->left == NULL) {
			return r;
		}
		else
			Findmin(r->left);
	}
	Node* Findmax(Node* r) {
		if (r == NULL) {
			return NULL;
		}
		else if (r->right == NULL) {
			return r;
		}
		else
			Findmax (r->right);
	}
	Node* Delete(Node* r, int key)
	{
		if (r == NULL) // Empty Tree
			return NULL;
		if (key < r->data) // Item exists in left sub tree
			r->left = Delete(r->left, key);
		else if (key > r->data) // item exists in right sub tree
			r->right = Delete(r->right, key);
		else
		{
			if (r->left == NULL && r->right == NULL) // leaf node
				r = NULL;
			else if (r->left != NULL && r->right == NULL) // one child on the left
			{
				r->data = r->left->data;
				delete r->left;
				r->left = NULL;
			}
			else if (r->left == NULL && r->right != NULL) // one child on the right
			{
				r->data = r->right->data;
				delete r->right;
				r->right = NULL;
			}
			else
			{
				Node* max = Findmax(r->left);
				r->data = max->data;
				r->left = Delete(r->left, max->data);

			}

		}
		return r;
	}
	


};

int main() {
	//45,15,79,90,10,55,12,20,50
	BST btree;
	btree.insert(45);
	btree.insert(15);
	btree.insert(79);
	btree.insert(90);
	btree.insert(10);
	btree.insert(55);
	btree.insert(12);
	btree.insert(20);
	btree.insert(50);
	cout << "Display Tree content\n";
	btree.Preorder(btree.root);
	cout << "\n-------------------------\n";
	btree.Inorder(btree.root);
	cout << "\n-------------------------\n";
	btree.Postorder(btree.root);
	cout << "\nenter item to search for \n";
	int key;
	cin >> key;
	if (btree.Search(key)) {
		cout << "Item found \n";
	}
	else
		cout << "Item not found\n";

	cout << "Find Minimum\n";
	Node* min = btree.Findmin(btree.root);
	if (min == 0) {//in c++ NUll equal to 0
		cout << "No items exist\n";
	}
	else {
		cout << "minimum is " << min->data << "\n";
	}
	cout << "Find maximum\n";
	Node* max = btree.Findmax(btree.root);
	if (max == 0) {
		cout << "No item exist \n";

	}
	else
		cout << "The maximum is " << max->data << "\n";




}