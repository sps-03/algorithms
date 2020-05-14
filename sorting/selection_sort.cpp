/*
SELECTION SORT:
	Sorts an array by repeatedly finding the minimum element and putting it at its correct place.
	The algorithm maintains two subarrays in the given array (1 sorted and 1 unsorted).
	To get completely sorted array we need n-1 iteration. In each iteration we will find the 
	minimum from unsorted subarray and put it in sorted subarray.
	After first pass we will have smallest element at the left end.

	Worst Case Time Complexity		: O(n*n). 
	Average Case Time Complexity	: O(n*n).
	Best Case Time Complexity		: O(n*n).
	Auxiliary Space 				: O(1)
	Sorting In Place 				: Yes
	Stable 							: By default it is not stable (But can be made so).

*/

#include <iostream>
using namespace std;

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);
	int min_index;

	for(int i=0 ; i<n-1; i++) {
		min_index = i;
		for(int j= i+1; j<n; j++) {
			if(arr[j] < arr[min_index])
				min_index = j;
		}
		//  XOR swapping with min element
		if(i != min_index) {
			arr[i] = arr[i] ^ arr[min_index];
			arr[min_index] = arr[i] ^ arr[min_index];
			arr[i] = arr[i] ^ arr[min_index];
		}
	}

	for(int i=0; i<n; i++)
		cout << arr[i] << " " ;
	return 0;
}