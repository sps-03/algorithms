/*
SUM OF SUBSETS:
    Given a set of values and a target. find whether a subset is possible with their sum equal to the 
    given target value.


    Time Complexity          : O(n*m)       // where, n = number of values in the given set
    Auxiliary Space          : O(n*m)       //        m = target value 
*/

#include <iostream>
using namespace std;


// returns true if true if there is a subset of values with sum equals target
bool subsetPossible(int values[], int target, int n) {
    // value of dp[i][j] will be true if there is a subset of values[0...i-1] 
    // with sum equals to j. (table will be filled in bottom up manner)
    bool dp[n+1][target+1];

    for(int i=0; i<=n; i++)       // for j==0, there will always be a subset (empty set) with sum equals j
        dp[i][0] = true;
    for(int j=1; j<=target; j++)  // for empty set there will be no subset with sum >= 1
        dp[0][j] = false;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=target; j++) {
            if(j < values[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-values[i-1]];
        }
    }

    return dp[n][target];
}

int main() {
    int values[] = {3, 13, 17, 7, 21};
    int target = 10;
    int n = sizeof(values)/sizeof(values[0]);

    if(subsetPossible(values, target, n))
        cout << "Subset with sum equals " << target << " is possible.\n";
    else
        cout << "Subset with sum equals " << target << " is not possible.\n";

    return 0;
}