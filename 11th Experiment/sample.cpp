#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int comparisonCount = 0;
int swapCount = 0;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for(int j = low; j <= high; j++) {
        comparisonCount++; 
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swapCount++; 
        }
    }
    swap(arr[i + 1], arr[high]);
    swapCount++; 
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int>& arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    vector<int> left(len1), right(len2);

    for(int i = 0; i < len1; i++) {
        left[i] = arr[s + i];
    }
    for(int i = 0; i < len2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex < len1 && rightIndex < len2) {
        comparisonCount++; 
        if(left[leftIndex] <= right[rightIndex]) {
            arr[mainArrayIndex++] = left[leftIndex++];
        } else {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
        swapCount++; 
    }
    while(leftIndex < len1) {
        arr[mainArrayIndex++] = left[leftIndex++];
        swapCount++;
    }
    while(rightIndex < len2) {
        arr[mainArrayIndex++] = right[rightIndex++];
        swapCount++;
    }
}

void mergeSort(vector<int>& arr, int s, int e) {
    if(s >= e) {
        return;
    }
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            comparisonCount++; 
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swapCount++; 
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisonCount++; 
            swapCount++; 
        }
        arr[j + 1] = key;
        swapCount++; 
    }
}

void printArray(const vector<int>& arr) {
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> ans(n);
    cout << "Enter " << n << " elements separated by space: ";
    for(int i = 0; i < n; i++) {
        cin >> ans[i];
    }

    int s = 0;
    int e = ans.size() - 1;
    int t;
    
   
    cout << "Sorting menu:" << endl;
    cout << "1. Merge sort" << endl;
    cout << "2. Quick sort" << endl;
    cout << "3. Selection sort" << endl;
    cout << "4. Insertion sort" << endl;

        int a;
        cout << "Enter your choice (1-4): ";
        cin >> a;
        comparisonCount = 0;
        swapCount = 0;

        switch(a) {
            case 1:
                mergeSort(ans, s, e);
                printArray(ans);
                cout << "Time complexity is O(n log n), comparisons: " << comparisonCount << ", swaps: " << swapCount << endl;
                break;
            case 2:
                quickSort(ans, s, e);
                printArray(ans);
                cout << "Time complexity for worst case is O(n^2), comparisons: " << comparisonCount << ", swaps: " << swapCount << endl;
                break;
            case 3:
                selectionSort(ans);
                printArray(ans);
                cout << "Time complexity for worst case is O(n^2), comparisons: " << comparisonCount << ", swaps: " << swapCount << endl;
                break;
            case 4:
                insertionSort(ans);
                printArray(ans);
                cout << "Time complexity for worst case is O(n^2), comparisons: " << comparisonCount << ", swaps: " << swapCount << endl;
                break;
            default:
                cout << "Invalid choice! Please choose again." << endl;
                break;
        }
    

    return 0;
}
