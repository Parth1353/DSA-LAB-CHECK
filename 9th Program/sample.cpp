#include <iostream>
#include <algorithm> // For swap function
using namespace std;

#define SIZE 50

class MaxPriorityQueue {
    double heap[SIZE];
    int size = -1;
    
    int parent(int i) {
        return (i-1)/2;
    }
    
    int leftChild(int i) {
        return 2*i + 1;
    }
    
    int rightChild(int i) {
        return 2*i + 2;
    }

public:
    void heapifyUP(int index);
    void heapifyDOWN(int index);
    void Insert(double x);
    void Display();
    double maximum();
    double extractMax();
};

void MaxPriorityQueue::heapifyUP(int index) {
    while(index > 0 && heap[parent(index)] < heap[index]) {
        swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}

void MaxPriorityQueue::heapifyDOWN(int index) {
    int max = index;

    if(leftChild(index) <= size && heap[leftChild(index)] > heap[max])
        max = leftChild(index);
    if(rightChild(index) <= size && heap[rightChild(index)] > heap[max])
        max = rightChild(index);

    if(max != index) {
        swap(heap[index], heap[max]);
        heapifyDOWN(max);
    }
}

void MaxPriorityQueue::Insert(double x) {
    heap[++size] = x;
    heapifyUP(size);
}

void MaxPriorityQueue::Display() {
    if(size == -1) {
        cout << "Priority Queue is empty!" << endl;
        return;
    }
    cout << "Max Priority Queue: ";
    for(int i = 0; i <= size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

double MaxPriorityQueue::maximum() {
    if(size == -1) {
        cout << "Priority Queue is empty!" << endl;
        return -1;
    } else {
        return heap[0];
    }
}

double MaxPriorityQueue::extractMax() {
    if(size == -1) {
        cout << "Max Priority Queue is empty!" << endl;
        return -1;
    }
    double max = heap[0];
    heap[0] = heap[size--];
    heapifyDOWN(0);
    return max;
}

int main() {
    MaxPriorityQueue pq;
    double num;
    int n, op;
    string cont;
    
    while(true) {
        cout << "Which operation do you want to perform?\n"
             << "1. Traverse\n"
             << "2. Insert\n"
             << "3. Display maximum element\n"
             << "4. Extract maximum element\n";
        cin >> op;

        switch(op) {
            case 1:
                pq.Display();
                break;
            case 2:
                cout << "How many elements do you want to insert? : ";
                cin >> n;
                for(int i = 0; i < n; i++) {
                    cout << "Enter an element to insert: ";
                    cin >> num;
                    pq.Insert(num);
                }
                break;
            case 3:
                cout << "Maximum element is: " << pq.maximum() << endl;
                break;
            case 4:
                cout << "The element " << pq.extractMax() << " has been extracted from the Priority Queue" << endl;
                break;
        }

        cout << "Do you wish to continue? (YES/No) : ";
        cin >> cont;
        if(cont != "YES" && cont != "yes" && cont != "Yes") {
            break;
        }
    }

    return 0;
}
