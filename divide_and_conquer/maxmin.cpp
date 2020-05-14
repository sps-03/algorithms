/*
MAX-MIN:
	Finds the maximum and minimum elements from a given array using Divide and Conquer technique.
	(same can done more efficiently using a for loop)
	
	Worst Case Time Complexity		: O(n)
	Average Case Time Complexity	: O(n)
	Best Case Time Complexity		: O(n)
	Auxiliary Space 				: O(1)
*/

#include <iostream>
#include <utility>
using namespace std;

pair<int, int> maxmin(int arr[], int low, int high) {
	pair<int, int> mm;				// mm.first-->max value
									// mm.second-->min value	
	if(low == high) {
		mm.first = arr[low];
		mm.second = arr[low];
	}
	else {
		int mid = low + (high-low)/2;					// divide step
		pair<int, int> mm1 = maxmin(arr, low, mid);		// conquer step
		pair<int, int> mm2 = maxmin(arr, mid+1, high);	// conquer step
		
		if(mm1.first > mm2.first)	mm.first = mm1.first;
		else 	mm.first = mm2.first;
		
		if(mm1.second < mm2.second)	mm.second = mm1.second;
		else	mm.second = mm2.second;
	}

	return mm;
}

int main() {
	int arr[] = {30, 70, 20, 50, 10, 80, 90, 40, 60};
	int n = sizeof(arr)/sizeof(arr[0]);

	pair<int, int> mm = maxmin(arr, 0, n-1);
	cout << "Max value = " << mm.first << endl;
	cout << "Min value = " << mm.second << endl;

	return 0;
}