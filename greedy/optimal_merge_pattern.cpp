/*
OPTIMAL MERGE PATTERN:
    Given N number of sorted arrays of different lengths, we need to find minimum number of moves 
    made to merge them into a single sorted array. note: Merging can be done by taking only two 
    arrays at a time (2-way merge).
    
    Merging of arrays of size 'm' and 'n' will make 'm + n' moves.
    Our objective is to make minimum number of moves to complete merging.
    Here we will use Greedy approach to solve the problem, ie. at each step we will select the 
    smallest two arrays and merge them. (we use min-heap for keeping track of different array size)
    

    Time Complexity                 : O(nlog(n))      // min-heap operations
    Auxiliary Space                 : O(n)            // min-heap
*/

#include <iostream>
#include <queue>
using namespace std;

int optimal_merge(int arr_lengths[], int n) {
    int moves = 0;
    priority_queue <int, vector<int>, greater<int>> minheap;

    for(int i=0; i<n; i++)
        minheap.push(arr_lengths[i]);                 // making heap

    while(minheap.size() > 1) {
        int len1 = minheap.top();   minheap.pop();    // get 2 smallest
        int len2 = minheap.top();   minheap.pop();
        moves += (len1 + len2);                       // add sum of 2 smallest to moves
        minheap.push(len1 + len2);                    // push back the sum
    }

    return moves;
}

int main() {
    int arr_lengths[] = {4, 6, 3, 1, 5, 8};           // represents size of each sorted array
    int n = sizeof(arr_lengths)/sizeof(arr_lengths[0]);

    cout << "Minimum moves required = " << optimal_merge(arr_lengths, n);

    return 0;
}