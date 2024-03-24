#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int sz) {
        size = sz;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isempty() {
        return front == -1;
    }

    bool isfull() {
        return (front == 0 && rear == size - 1) || (rear == front - 1);
    }

    void enqueue(int data) {
        if (isfull()) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) {
                front = 0;
                rear = 0;
            } else if (rear == size - 1) {
                rear = 0;
            } else {
                rear++;
            }
            arr[rear] = data;
        }
    }

    int dequeue() {
        if (isempty()) {
            return -1; // Queue is empty
        } else {
            int data = arr[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else if (front == size - 1) {
                front = 0;
            } else {
                front++;
            }
            return data;
        }
    }

    int peek() {
        if (isempty()) {
            return -1; // Queue is empty
        } else {
            return arr[front];
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            if (front <= rear) {
                while (i <= rear)
                    cout << arr[i++] << " ";
            } else {
                while (i < size)
                    cout << arr[i++] << " ";
                i = 0;
                while (i <= rear)
                    cout << arr[i++] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;
    CircularQueue cq(size);

    int choice, data;

    while (true) {
        cout << "Choose an operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Front\n";
        cout << "4. Display Queue\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> data;
                cq.enqueue(data);
                break;
            case 2:
                data = cq.dequeue();
                if (data == -1) {
                    cout << "Queue is empty. Dequeue failed." << endl;
                } else {
                    cout << "Dequeued element: " << data << endl;
                }
                break;
            case 3:
                data = cq.peek();
                if (data == -1) {
                    cout << "Queue is empty. No front element." << endl;
                } else {
                    cout << "Front element: " << data << endl;
                }
                break;
            case 4:
                cq.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
