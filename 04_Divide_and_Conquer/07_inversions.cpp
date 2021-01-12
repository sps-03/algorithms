/*
NUMBER OF INVERSIONS:
	Given an array A, it returns the number of inversions.
	Inversion means for two indices i & j such that i < j we will have A[i] > A[j].

	Here we will use a slightly modified version of merge() which we used for merge_sort.

	Worst Case Time Complexity		: O(nlogn)
	Average Case Time Complexity	: O(nlogn)
	Best Case Time Complexity		: O(nlogn)
	Auxiliary Space					: O(n)
*/

#include <iostream>
using namespace std;


int merge(int arr[], int low, int mid, int high, int num_inv_left, int num_inv_right) {
	int num_inv = num_inv_left + num_inv_right;	// number of inversions in the left & right subarrays.
	int n = high-low+1;							// number of elements in the left & right subarrays.
	int temp[n];								// temp array to do sorting.
	int idx = 0, i = low, j = mid+1;

	while(i<=mid && j<=high) {
		if(arr[i] > arr[j]) {					// inversion condition
			temp[idx] = arr[j];
			idx++; j++;
			num_inv += mid-i+1;					// add num of inversions ie, from 'i' till 'mid'.
		}
		else {
			temp[idx] = arr[i];
			idx++; i++;
		}
	}
	while(i<=mid) {
		temp[idx] = arr[i];
		idx++; i++;
	}
	while(j<=high) {
		temp[idx] = arr[j];
		idx++; j++;
	}

	for(idx=0; idx<n; idx++)		// copy to original array.
		arr[low+idx] = temp[idx];

	return num_inv;					// return total inversions after merging.
}

int inversions(int arr[], int low, int high) {
	if(low == high)	return 0;

	int mid = low + (high-low)/2;
	int num_inv_left = inversions(arr, low, mid);
	int num_inv_right = inversions(arr, mid+1, high);

	return merge(arr, low, mid, high, num_inv_left, num_inv_right);
}

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "The number of inversions in the given array is " << inversions(arr, 0, n-1);
	return 0;
}