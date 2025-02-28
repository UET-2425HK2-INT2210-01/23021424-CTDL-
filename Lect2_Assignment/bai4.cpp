#include <iostream>
#include <string>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    Queue() : front(nullptr), rear(nullptr) {}
    bool isEmpty() {
        return (front == nullptr);
    }
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }


    bool dequeue() {
        if (isEmpty()) {
            return false;
        }
        Node* temp = front;
        front = front->next; 
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return true;
    }

    int peek() {
        if (isEmpty()) {
            return -1; 
        }
        return front->data;
    }

    void printQueue() {
    
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    
    }
};

int main() {
    Queue q;
	int n, value; 
	string word;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> word;
		if (word == "enqueue"){
			cin >> value;
			q.enqueue(value);
		}
		else {
			q.dequeue();
		}
	}
  
    q.printQueue();  

   system("pause");
}
