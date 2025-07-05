#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<int> q;       // Built in function 
    // Adding/ Pushing/ Insertion element in queue      --  At back/rear end         -- Using q.push(val);
    // Popping/ Deleting element from queue         --  From front end      -- Using q.pop();
    // To access 1st element of queue           -- Use q.front();
    // To access last element of queue          -- Use q.back();
    // To find size of queue                   -- Use q.size(); 
    // To check if queue is empty or not        -- Use q.empty();           -- It is true or false 

    // Queue supports FIFO and LILO
    // FIFO - First In First Out
    // LILO - Last In Last Out

    // Insertion happens only at the back/ rear         -- Using push() operation           -- T.C = O(1)
    // Popping/ Deleting happens only at the front      -- Using pop() operation            -- T.C = O(1) 
    // size() -- Returns the size of queue      -- T.C = O(1)
    // front() -- Returns the first element (front) of queue        -- T.C = O(1)
    // back() -- Returns the last/rear element (back) of queue          -- T.C = O(1)
    // empty() -- Returns "true" if size() == 0 else return "false"

    // "Overflow" only happens if we implement the queue via an array if we fill the array
    // "Underflow" happens whenever the queue is empty and we try to use these functions -- pop(), front(), back()  

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // 10 20 30 40 50 
    cout << q.front() << endl;      // 10
    cout << q.back() << endl;       // 50
    cout << q.size() << endl;       // 5
    cout << q.empty() << endl;      // 0 or FALSE because queue is not empty
    q.pop();
    // Now after popping/ deleting the first element 
    cout << q.front() << endl;      // 20
    cout << q.back() << endl;       // 50
    cout << q.size();               // 4
}