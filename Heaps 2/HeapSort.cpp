// Heap Sort - Can be implemented using MinHeap or MaxHeap  
// Time Complexity = O(n*logn)      : Same as Merge Sort or Quick Sort 
// Space Complexity = O(n)

// For Merge Sort: 
// Time Complexity = O(n*logn)     
// Space Complexity = O(n)

// For Quick Sort: 
// Time Complexity = O(n*logn)      
// Space Complexity = O(logn)

// Algorithm: 
// Firstly, implement a MaxHeap using array (visualise using Binary Tree)
// Then, put idx = size, and the put arr[idx] = arr[1](Top of heap) use pop() function - so rearrangement occurs 
// Similarly iterate from last to first to update the array for Heap 


// Heapify Algorithm: 
// convert given array into Heap