#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
};
class Stack {

	Node* top;

public:
	Stack() {
		top = NULL;
	}
	bool isempty() {
		if (top == NULL) {
			return true;
		}
		else
			return false;
	}

	bool isFull() {
		Node* ptr = new Node();  /// if heap is full ptr by default will equal to NULL 
		if (ptr == NULL) {
			cout << "The stack is Full\n";
		}
	}
	void push(int item) {
		Node* newnode = new Node();
		newnode->data = item;
		if (isempty()) {

			newnode->next = NULL;
			top = newnode;
		}
		else
			newnode->next = top;
		top = newnode;
	}


	int pop() {
		Node* delptr = top;
		int value;
		value = top->data;
		top = top->next;
		delete delptr;
		return value;
	}

	int peek() {

		return top->data;

	}
	void display() 
	{
		Node* temp = top;
		while (temp != NULL) {
			cout << temp->data << "\n";
			temp = temp->next;
			
		}
 
	}
	int ctr()
	{
		int counter = 0;
		Node* temp = top;
		while (temp != NULL) {
			cout << temp->data << "\n";
			temp = temp->next;
			counter++;

		}

		return counter;
	}


	bool isfound(int item) {
		Node* temp=top;
		while (temp != NULL) {
			if (temp->data == item) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	

};


int main() {
	

	int item;
	Stack s;
	for (int i = 0; i < 3; i++) {
		cout << "Enter item to push \n";
		cin >> item;
		s.push(item);
		s.display();

	}
	cout << s.pop() << "was deleted from stack \n";

	cout << "Enter item to search for \n";
	cin >> item;
	if (s.isfound(item)) {
		cout << "item" << item << " found\n";
	}
	else
		cout << "Item isn't found \n";

	//cout << s.pop() << "was deleted from stack \n";

}