#include<iostream>
using namespace std;

class circularqueue {
    int* arr;
    int currSize, capacity;
    int front, rear;

public:
    circularqueue(int size) {
        capacity = size;
        arr = new int[capacity]; 
        currSize = 0;
        front = 0;
        rear = -1;
    }

    void push(int val) {
        if (currSize == capacity) {
            cout << "queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        currSize++;
    }

    void pop() {
        if (currSize == 0) { 
            cout << "queue is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        currSize--;
    }

    int getFront() {
        if (currSize == 0) {
            cout << "queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        return currSize == 0;
    }

    ~circularqueue() {
        delete[] arr; 
    }
};

int main() {
    circularqueue aa(3);
    aa.push(3);
    aa.push(8);
    aa.push(9);
    
    while (!aa.empty()) {
        cout << aa.getFront() << " ";
        aa.pop();
    }

    return 0;
}
