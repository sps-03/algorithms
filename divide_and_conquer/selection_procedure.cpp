/*
SELECTION PROCEDURE:
	Given an array A and an interger K, return the K_th smallest element.
	Here we will use a slightly modified version of partition() which we used for quick_sort.

	Worst Case Time Complexity		: O(n*n)
	Average Case Time Complexity	: O(n)
	Best Case Time Complexity		: O(n)
	Auxiliary Space					: O(1)
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

int select(int arr[], int low, int high, int k) {
	int m = partition(arr, low, high);				// gets the index of pivot
	if(m == k-1)		return arr[m];				// (k-1) is used since indexing starts from 0.
	else if(m < k-1)	return select(arr, m+1, high, k);
	else 				return select(arr, low, m-1, k);
}

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 4;

	cout << "The " << k << "th smallest element is " << select(arr, 0, n-1, k);
	
	return 0;
}