/*
INSERTION SORT:
	Start iterating from index 1 till index n-1 and for each iteration 'i' take element arr[i] 
	and place it in its proper position among elements to the left of 'i' so that elements to the
	left of 'i' will be in sorted order among themselves. 

	Worst Case Time Complexity		: O(n*n). Reverse sorted array.
	Average Case Time Complexity	: O(n*n).
	Best Case Time Complexity		: O(n). Sorted array.
	Auxiliary Space					: O(1)
	Sorting In Place				: Yes
	Stable							: Yes

*/

#include <iostream>
using namespace std;

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=1 ; i<n; i++) {
		for(int j= i-1; j>=0; j--) {
			if(arr[j] > arr[j+1]) {
				//  XOR swapping
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
			}
			else
				break;
		}
	}

	for(int i=0; i<n; i++)
		cout << arr[i] << " " ;
	return 0;
}