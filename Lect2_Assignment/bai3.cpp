#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}


    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
	int sumTriples() {
		Node* current = head;
		int dem =0;
        while (current != nullptr && current->next != nullptr && current->next->next != nullptr) {
            int sum = current->data + current->next->data + current->next->next->data;
			if (sum == 0 ) dem++;
            current = current->next; 
        }
		return dem;
    }
};

int main() {
    DoublyLinkedList doubleLL;
    
   int n,value;
   cin>> n;
   for (int i = 0; i<n; i++){
		cin >> value;
		doubleLL.insertEnd(value);
   }
   cout << doubleLL.sumTriples()<<endl;
    system("pause");
}
