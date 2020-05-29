/*
BINARY KNAPSACK:
	We are given weights and values for N items and a knapsack of limited capacity.
	We need to put these items into the knapsack in such a way that the total value of items 
	in the knapsack will be maximum. but there is one condition that if we are taking an item 
	we need to take it completely else avoid that item (so it is different from binary knapsack).

	Here, we will use Dynamic Programming.
	We can use tabulation method in which all possible weights (from 1 to W) are represented as 
	the columns and the number of items that can be kept are represented as the rows.
	
	The state DP[i][j] will denote maximum value that can be obtained for a total wieght of 'j' 
	considering all items till 'i’th item.


    Time Complexity          : O(n*W)       // where, n is the number of items & 
    Auxiliary Space          : O(n*W)       //        W is the capacity of knapsack
*/

#include <iostream>
using namespace std;


// structure to represent an item with a specific value and weight
struct Item {
    int value, weight;
};

int binary_knapsack(Item arr[], int n, int W) {
	int dp[n+1][W+1];

	for(int i=0; i<=n; i++) {          // fill the table in bottom up manner
		for(int w=0; w<=W; w++) {
			if(i==0 || w==0)
				dp[i][w] = 0;
			else if(arr[i-1].weight <= w)
				dp[i][w] = max(arr[i-1].value + dp[i-1][w-arr[i-1].weight], dp[i-1][w]);
			else
				dp[i][w] = dp[i-1][w];
		}
	}

	return dp[n][W];
}

int main() {
	int capacity = 10;    // capacity of the knapsack
    Item arr[] = {{60, 10}, {100, 5}, {150, 3}, {80, 8}, {30, 1}, {50, 2}};
	int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum value possible = " << binary_knapsack(arr, n, capacity);

    return 0;
}