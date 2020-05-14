/*
QUICK SORT:
	It is a Divide and Conquer algorithm. Here we pick an element as pivot and partitions 
	the given array around the pivot (pivot can be choosen in different ways). 
	
	The key process in quickSort is partition() in which the pivot 'x' will be put in its 
	correct position while all elements smaller than that goes to its left side and 
	all elements larger than that goes to its right. At the end position where pivot got 
	placed will be returned (it should be done in linear time).

	Worst Case Time Complexity		: O(n*n). Worst case occurs when the choosen pivot is the
												smallest or largest element at each step.
	Average Case Time Complexity	: O(nlogn).
	Best Case Time Complexity		: O(nlogn). Best case occurs when array is partitioned into 
												two equal parts at each step.
	Auxiliary Space					: O(1)
	Sorting In Place 				: Yes
	Stable							: No (deafult)

	QuickSort is faster in practice, because its inner loop can be efficiently implemented on 
	most architectures, and in most real-world data. QuickSort can be implemented in different 
	ways by changing the choice of pivot, so that the worst case rarely occurs for a given type 
	of data. However, merge sort is generally considered better when data is huge and 
	stored in external storage.

*/

#include <iostream>
using namespace std;

int partition(int a[], int low, int high) {
	int pivot = a[high];					// always taking the last element as the pivot.
	int pos = low;
	for(int i=low; i<high; i++) {			// iterate through elements and place them properly.
		if(a[i] < pivot) {					// smaller at the left side and larger at the right side.
			int temp = a[pos]; 
			a[pos] = a[i];
			a[i] = temp;
			pos++;
		}
	}
	int temp = a[pos]; 						// place pivot at its correct position
	a[pos] = a[high];
	a[high] = temp;
	return pos;								// return pivot position
}

void quicksort(int a[], int low, int high) {
	if(low < high) {
		int p = partition(a, low, high);	// gets the pivot position and 
		quicksort(a, low, p-1);				// recursively calling quicksort on
		quicksort(a, p+1, high);			// left part and right part.
	}
}

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);

	quicksort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout << arr[i] << " " ;
	return 0;
}