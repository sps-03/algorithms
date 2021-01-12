/*
BUBBLE SORT:
	Compare two adjacent elements one by one, then place the bigger one on the right side.
	After first pass we will have largest element at the right end.
	(so we need a total of n-1 passes)

	Worst Case Time Complexity		: (n*n). Worst case occurs when array is reverse sorted.
	Average Case Time Complexity	: (n*n).
	Best Case Time Complexity		: O(n). Best case occurs when array is already sorted.
	Auxiliary Space					: O(1)
	Sorting In Place				: Yes
	Stable							: Yes

*/

#include <iostream>
using namespace std;

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0 ; i<n-1 ; i++) {
		for(int j= 0; j<n-i-1 ; j++) {
			if(arr[j] > arr[j+1]) {
				// XOR swapping
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
			}
		}
	}

	for(int i=0; i<n; i++)
		cout << arr[i] << " " ;
	return 0;
}