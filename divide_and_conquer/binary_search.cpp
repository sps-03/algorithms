/*
BINARY SEARCH:
	It's applicable only on sorted arrays.
	Since the array is sorted it will look at the middle element and compare it with the 
	searched element if they are equal it will return the index else it will choose either 
	of the two halves depending on the value of middle element and searched element. This process 
	will be repeated until the element is found or range gets exhausted.

	Worst Case Time Complexity		: O(log(n))
	Average Case Time Complexity	: O(log(n))
	Best Case Time Complexity		: O(log(n))
	Auxiliary Space					: O(1)

*/

#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int val) {
	int left = 0, right = n-1;
	
	while(left <= right) {
		int mid = left + (right - left)/2;

		if(arr[mid] == val)
			return mid;
		else if(arr[mid] < val)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main() {
	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	int n = sizeof(arr)/sizeof(arr[0]);

	int element = 80;
	int idx = binary_search(arr, n, element);
	if(idx != -1)
		cout << "The element " << element << " is present at the index " << idx << endl;
	else
		cout << "The element " << element << " is not present in the given array" << endl;

	return 0;
}