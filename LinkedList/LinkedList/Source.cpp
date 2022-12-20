#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

};
class Linkedlist {
public:
	Node* head;
	Linkedlist() {
		head = NULL;
	}
	bool isempty() {
		return (head == NULL);
	} 

	void insertFirst(int newvalue) {
		Node* newnode=new Node();
		newnode->data = newvalue;
		if (isempty()) {
			
			newnode->next = NULL;
			head = newnode;


		}
		else {
			
			newnode->next = head;
			head = newnode;
		}
	}
	void display() {
		Node* tmp;
		tmp = head;
		while (tmp != NULL) {
			cout << tmp->data << " ";
			tmp = tmp->next;

		}
		cout << "\n";
	}
	int count() {
		Node* temp;
		temp = head;
		int ctr=0;
		while (temp != NULL) {
			ctr++;
			temp = temp->next;
		}
		return ctr;
	}
	bool isfound(int key) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == key) {
				return true;
			}
		}
		return false;
	}
	void insertbefore(int item, int newvalue) {

		if (isfound(item)) {

			Node* newnode = new Node();
			newnode->data = newvalue;

			Node* tmp;
			tmp = head;
			while (tmp != NULL && tmp->next->data != item) {
				tmp = tmp->next;
			}
			newnode->next = tmp->next;
			tmp->next = newnode;
		}
		else {
			cout << "Sorry, Item not found\n";
		}

	}
	void append(int newitem) {
		if (isempty())
			insertFirst(newitem);
		else {}
			Node* tmp = new Node();
			tmp = head;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			Node* newnode = new Node();
			newnode->data = newitem;
			tmp->next = newnode;
			newnode->next = NULL;
	}
	void Delete(int item) {
		Node* delptr = head;
		if (isempty()) {
			cout << "List is empty \n";
		}
		else if (head->data == item) {
			
			head = head->next;
			delete delptr;
		}
		else {
			Node* prev = NULL;
			while (delptr->data != item) {
				prev = delptr;
				delptr = delptr->next;
			}

		}

	}

};


int main() {
	Linkedlist lst;
	if (lst.isempty()) {
		cout << "list is empty\n";
	}
	else {
		cout << "the list contains " << lst.count() << "\n";
	}
	int item;
	cout << "Enter item to insert in the list \n";

	cin >> item;
	lst.insertFirst(item);
	lst.display();
	cout << "Enter item to insert in the list \n";

	cin >> item;
	lst.insertFirst(item);
	lst.display();
	cout << "Enter item to search for \n";
	cin >> item;

	if (lst.isfound(item)) {
		cout << "Item found \n";
	}
	else
		cout << "Item NOT Found \n";

	int newvalue;
	cout << "Enter item and new value to insert\n";
	cin >> item;
	cin >> newvalue;
	lst.insertbefore(item, newvalue);
	lst.display();

	
}