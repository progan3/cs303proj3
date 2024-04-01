using namespace std;
#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* frontPtr;
    Node* rearPtr;
    int count;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    void push(T data) { //pushes value to queue
        Node* newNode = new Node(data);
        if (empty()) {
            frontPtr = rearPtr = newNode;
        }
        else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
        ++count;
    }

    void pop() { //pops value from queue
        if (!empty()) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
            --count;
            if (count == 0) {
                rearPtr = nullptr;
            }
        }
    }

    T front() { //returns front value
        if (!empty()) {
            return frontPtr->data;
        }
        throw out_of_range("Queue is empty");
    }

    int size() { //returns size
        return count;
    }

    bool empty() { //checks if empty
        return count == 0;
    }

    void move_to_rear() {
        if (count > 1) {
            push(front());
            pop();
        }
    }
};

int main() {
    //question A
    Queue<int> q;
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }
    //question B
    cout << "Queue elements:" << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    //Question C
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }
    q.move_to_rear();

    cout << "Queue after moving front to rear:" << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
