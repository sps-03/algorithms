/*
MATRIX CHAIN MULTIPLICATION:
	Given a sequence of matrices (A1, A2, A3, ..., An) to multiply, we need to find the minimum number 
	of scalar multiplications needed to find the product.

	We have many options to multiply a chain of matrices because matrix multiplication is associative. 
	In other words, no matter how we parenthesize the product, the result will be the same. 
	For example, if we had four matrices A, B, C, and D, we would have:
	    (ABC)D = (AB)(CD) = A(BCD) = .... , but the number of scalar multiplications will be different.

	Recursive function to find minimum number of scalar multiplications required for multiplying 
	matrices from i to j is given by:
		m[i, j] = min(m[i, k] + m[k+1, j] + d[i-1]*d[k]*d[j])   where,  1 <= k < n and
                                                                        d[] means dimension
	also, m[i, i] = 0


    Time Complexity          : O(n*n*n)
    Auxiliary Space          : O(n*n)
*/

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;


int MatrixChain(int d[], int n) {
	int m[n][n];             // extra row and column is for simplicity (row-0 and col-0 won't be used)
	memset(m, 0, sizeof(m)); // set all values to zero

    for(int chain_len=1; chain_len < n-1; chain_len++) {   // start filling in diagonal manner
        for(int i=1; i < n-chain_len; i++) {
            int j = i+chain_len;
            m[i][j] = INT_MAX;
            for(int k=i; k <= j-1; k++) {
                int q = m[i][k] + m[k+1][j] + d[i-1] * d[k] * d[j];
                m[i][j] = min(q, m[i][j]);
            }
        }
    }

	return m[1][n-1];
}

int main() {
	// dimensions of matrices are given
	int dims[] = {5, 4, 6, 2, 7};      // matrix Ai has dimension dims[i-1] x dims[i] for i=1 to n
	int size = sizeof(dims)/sizeof(dims[0]);

	cout << "Minimum number of multiplications required is " << MatrixChain(dims, size) << "\n";

    return 0;
}