#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
class Stack {
public:
	Node* top = NULL;
	void push(int item) {
		Node* newNode = new Node();
		newNode->data = item;
		if (top == NULL) {
			top = newNode;
			newNode->next = NULL;

		}
		else {
			newNode->next = top;
			top = newNode;
		}
	}
	void display() {
		Node* temp = top;
		cout << "the Elements \n";
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	bool isEmpty() {
		return(top == NULL);
	}
	bool isFound(int item) {
		bool found = false;
		Node* temp = top;
		while (temp != NULL) {
			if (temp->data == item)
				found = true;
			temp = temp->next;
		}
		return found;

	}
	int pop() {
		int value;
		Node* dlptr = top;
		top = top->next;
		value = dlptr->data;
		delete dlptr;
		return value;
	}
	int peek() {
		return top->data;
	}
	int count() {
		Node* temp = top;
		int counter = 0;
		while (temp != NULL) {
			counter++;
			temp = temp->next;
		}
		return counter;
	}
};
int main() {
	int item;
	Stack st;
	for (int i = 0; i < 4; i++) {
		cout << "Enter the element you want to push \n";
		cin >> item;
		st.push(item);
		st.display();

	}
	cout << "the Number Of Element is " << st.count() << endl;
	cout << "the deleted Item is \t" << st.pop() << endl;
	st.display();
	int ele;
	cout << "Enter the Element you want to search it\n";
	cin >> ele;
	if (st.isEmpty()) {
		cout << "the Stack Is Empty\n";
	}
	else {
		if (st.isFound(ele)) {
			cout << "The element is found\n";
		}
		else {
			cout << "The Element Not Found\n";
		}
		cout << "the peek is\t" << st.peek() << endl;
	}
}