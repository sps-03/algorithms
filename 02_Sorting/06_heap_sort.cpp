/*
HEAP SORT:
	Heap sort is a comparison based sorting technique based on Binary Heap data structure.
	
	A Binary Heap is a Complete Binary Tree where items are stored in a special order such 
	that value in a parent node is greater (or smaller) than the values in its two children nodes. 
	The former is called as max-heap and the latter is called min-heap. 
	
	The heap can be represented by binary tree or array. 
	Since a Binary Heap is a Complete Binary Tree, it can be easily represented as array 
	and array based representation is space efficient. 
	If the parent node is stored at index idx, the left child can be calculated by (2*idx)+1 
	and right child by (2*idx)+2 (assuming the indexing starts at 0).

	Heap Sort Algorithm for sorting in increasing order:
		1. Build a max heap from the input data.
		2. At this point, the largest item is stored at the root of the heap. Replace it with the 
		   last item of the heap followed by reducing the size of heap by 1. Finally, heapify the 
		   root of tree.
		3. Repeat above steps while size of heap is greater than 0.

	Time complexity of heapify is O(logn).

	Worst Case Time Complexity		: O(nlogn)
	Average Case Time Complexity	: O(nlogn)
	Best Case Time Complexity		: O(nlogn)
	Auxiliary Space 				: O(1)
	Sorting In Place 				: Yes
	Stable							: No (deafult)

	Heap sort algorithm has limited uses because Quicksort and Mergesort are better in practice.

*/

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int r) 	// to heapify a subtree with size n having root node at r.
{ 
    int largest = r; 					// initialize largest as root 
    int left = 2*r + 1; 				// to get left child index
    int right = 2*r + 2; 				// to get right child index
  
    if (left < n && arr[left] > arr[largest]) 	// if left child is larger than root 
        largest = left; 
    if (right < n && arr[right] > arr[largest]) // if right child is larger than largest so far 
        largest = right; 
  
    if (largest != r) 					// if largest is not root 
    { 
        swap(arr[r], arr[largest]); 
        heapify(arr, n, largest); 		// recursively heapify the affected sub-tree 
    } 
}

void heapsort(int arr[], int n) 
{ 
    for (int i = (n/2)-1; i >= 0; i--) 	// build heap from the given array
        heapify(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 			// one by one extract an element from heap
    {  
        swap(arr[0], arr[i]); 			// move current root to end
        heapify(arr, i, 0); 			// call max heapify on the reduced heap 
    } 
} 

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);

	heapsort(arr, n);

	for(int i=0; i<n; i++)
		cout << arr[i] << " " ;
	return 0;
}