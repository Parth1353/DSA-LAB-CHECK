#include <iostream>
#include <vector>

using namespace std;


class MaxPriorityQueue {
private:
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void swap(int i, int j) {
        int temp = heap[i];
        
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void heapify(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(i, largest);
            heapify(largest);
        }
    }


public:
    void insert(int key) {
        heap.push_back(key);
        int index = heap.size() - 1;
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(index, parent(index));
            index = parent(index);
        }
    }


    int extractMax() {
        if (heap.empty()) {
            return -1e9; 
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return max;
    }

    int peekMax() {
        if (heap.empty()) {
            return -1e9; 
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

int main() {
    MaxPriorityQueue pq;
     while(true){
        cout<<"Enter 1 to insert\nEnter 2 to get max value\nEnter 3 to remove max Priority element\nEnter 4 to get size"<<endl;
        int n;
        cin>>n;

        if(n==1){
           cout<<"Enter element to inset"<<endl;
           int a;
           cin>>a;
           pq.insert(a);
        }else if(n==2){
            cout<<"Max Priority element is : "<<pq.peekMax()<<endl;

        }else if(n==3){
             pq.extractMax();
             cout<<"Max priority element removed"<<endl;
        }else if(n==4){
           cout<<"Size of maxpriorityQueue is : "<<pq.size()<<endl;
        }else{
            break;
        }
     }

}