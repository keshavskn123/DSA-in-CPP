#include<iostream>
using namespace std;
class MaxHeap {
public: 
    int arr[50];
    int idx;

    MaxHeap() {     // Default Constructor
        idx = 1;
    }

    int top() {
        return arr[1];
    }

    void push(int x) {
        arr[idx] = x;
        int i = idx;
        idx++;
        while(i>1) {
            int parent = i/2;
            if(arr[i] > arr[parent]) {      
                swap(arr[i], arr[parent]);      // swapping
                i = parent;     // i= i/2;
            }
            else break;
        }
    }

    void pop() {
        idx--;
        arr[1] = arr[idx];
        // rearrangement
        int i = 1;

        while(true) {
            int left = 2*i, right = 2*i + 1;
            if(left > idx-1) break;     // size = idx-1         -- if leftChild and rightChild doesn't exist  
            if(right > idx-1) {         // if rightChild doesn't exist  
                if(arr[i] < arr[left]) {
                    swap(arr[i], arr[left]);
                    i = left;
                    continue;
                }
                else break;
            }

            if(arr[left] < arr[right]) {
                if(arr[i] < arr[right]) {
                    swap(arr[i], arr[right]);
                    i = right;
                }
                else break;
            }
            else {      // if(arr[right] < arr[left])
                if(arr[i] < arr[left]) {
                    swap(arr[i], arr[left]);
                    i = left;
                }
                else break;
            }
        }
    }

    int size() {
        return idx-1;
    }

    void display() {
        for(int i=1; i<=idx-1; i++) {
            cout << arr[i] << " ";
        }
    }
};
int main() {
    MaxHeap pq ;
    pq.push(10);
    pq.push(20);
    cout << pq.top() << " " << pq.size() << endl;
    pq.push(11);
    pq.push(2);
    cout << pq.top() << " " << pq.size() << endl;
    pq.display();
    cout << endl;
    pq.pop();
    cout << pq.top() << " " << pq.size() << endl;
    pq.display();
    cout << endl;
}