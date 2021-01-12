/*
FRACTIONAL KNAPSACK:
	We are given weights and values for N items and a knapsack of limited capacity.
	We need to put these items into the knapsack in such a way that the total value of items 
	in the knapsack will be maximum.

	Here we will use Greedy approach.
	The basic idea here is to calculate the ratio 'value/weight' for each item and sort the items 
	on basis of this ratio. Then take the items with the highest ratio and add them until we can’t 
	add the next item as a whole and at the end add the next item as much as we can. Which will 
	always be the optimal solution to this problem.

	Time Complexity                 : O(nlog(n))      // as sorting is done
	Auxiliary Space                 : O(1)

*/

#include <iostream>
#include <algorithm>
using namespace std;

 
struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double) a.value/a.weight;
    double r2 = (double) b.value/b.weight;
    return r1>r2;
}

double fractional_knapsack(Item arr[], int n, int capacity) {
    sort(arr, arr+n, compare);                 // sorting items on the basis of value/weight ratio

    int cur_knapsack_weight = 0;               // total weight of items in the knapsack
    double total_knapsack_value = 0;           // total value of items in the knapsack

    for (int i = 0; i < n; i++) {
    	// if no overflow then add the item completely
        if (cur_knapsack_weight + arr[i].weight <= capacity) {
            cur_knapsack_weight += arr[i].weight;
            total_knapsack_value += arr[i].value;
        }

        // if we can't add current item completely then add fractional part of it
        else {
            int remain = capacity - cur_knapsack_weight;
            total_knapsack_value += arr[i].value * ((double) remain/arr[i].weight);
            break;
        }
    }

    return total_knapsack_value;
}

int main() {
	int capacity = 10;    // capacity of the knapsack
    Item arr[] = {{60, 10}, {100, 5}, {150, 3}, {80, 8}, {30, 1}, {50, 2}};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum value possible = " << fractional_knapsack(arr, n, capacity);
    return 0;
}