/*
LINEAR SEARCH:
	Search array elements one by one starting from the beginning till the end.
	If searched element is present it will return the index of its first occurance else if the 
	searched element is not present it will return -1.

	Worst Case Time Complexity		: O(n)
	Average Case Time Complexity	: O(n)
	Best Case Time Complexity		: O(n)
	Auxiliary Space					: O(1)

*/

#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int val) {
	for(int i=0; i<n; i++) {
		if(arr[i] == val)
			return i;
	}
	return -1;
}

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);

	int element = 80;
	int idx = linear_search(arr, n, element);
	if(idx != -1)
		cout << "The element " << element << " is present at the index " << idx << endl;
	else
		cout << "The element " << element << " is not present in the given array" << endl;

	return 0;
}