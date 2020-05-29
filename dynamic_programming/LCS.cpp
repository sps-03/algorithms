/*
LONGEST COMMON SUBSEQUENCE:
    Given two sequences, find the length of longest subsequence present in both of them.
    A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
    For example, “abc”, “abg”, “bdf”, “aeg”, ”acefg”, ... are subsequences of “abcdefg”.

	Here, we can apply Dynamic Programming.
	We can use tabulation method where dp[i][j] represents the length of LCS for first sequence till 'i' 
	and second sequence till 'j'.


    Time Complexity          : O(m*n)       // where, m and n are length of given sequences.
    Auxiliary Space          : O(m*n)
*/

#include <iostream>
using namespace std;


int LCS(string s1, string s2, int m, int n) {
	int dp[m+1][n+1];

	for(int i=0; i<=m; i++) {          // build the table in bottom up manner
		for(int j=0; j<=n; j++) {
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

		}
	}

	return dp[m][n];
}

int main() {
	string s1 = "ABCBBDEFF";           // Here LCS is 'BDEFF'
	string s2 = "BDAABEAFCF";

	int n1 = s1.size();
	int n2 = s2.size();

	cout << "Length of Longest Common Subsequence is " << LCS(s1, s2, n1, n2) << "\n";

    return 0;
}