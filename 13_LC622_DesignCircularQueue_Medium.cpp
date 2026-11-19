// LeetCode 622 - Design Circular Queue (Medium)
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int capacity;
    int frontIndex;
    int rearIndex;
    int currentSize;

public:
    MyCircularQueue(int k)
        : data(k), capacity(k), frontIndex(0), rearIndex(0), currentSize(0) {}

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        data[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        currentSize++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : data[frontIndex];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(rearIndex - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }
};
