/*
MERGE SORT:
	It is a Divide and Conquer algorithm. Here we divide the input array in two halves, calls itself 
	for the two halves and then merges the two sorted halves. 

	The merge() function is used for merging two halves. 
	The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are 
	sorted and merges the two sorted sub-arrays into one.

	Worst Case Time Complexity		: O(nlogn).
	Average Case Time Complexity	: O(nlogn).
	Best Case Time Complexity		: O(nlogn).
	Auxiliary Space					: O(n)
	Sorting In Place 				: No
	Stable							: Yes

*/

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	int n = right-left+1;				// total elements to merge.
	int temp[n];						// temp array to hold sorted values.
	int idx = 0, i = left, j = mid+1;

	while(i<=mid && j<=right) {
		if(arr[i] < arr[j]) {
			temp[idx] = arr[i];
			idx++; i++;
		}
		else {
			temp[idx] = arr[j];
			idx++; j++;
		}
	}
	while(i<=mid) {
		temp[idx] = arr[i];
		idx++; i++;
	}
	while(j<=right) {
		temp[idx] = arr[j];
		idx++; j++;
	}

	for(idx=0; idx<n; idx++)		// copy to original array.
		arr[left+idx] = temp[idx];
}

void mergesort(int arr[], int left, int right) {
	if(left < right) {
		int mid = left + (right-left)/2; // same as (left+right)/2 but this method avoids overflow.
		
		mergesort(arr, left, mid);		// sort 2 halves.
		mergesort(arr, mid+1, right);
		
		merge(arr, left, mid, right);	// then merge sorted halves.
	}
}

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);

	mergesort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout << arr[i] << " " ;
	return 0;
}