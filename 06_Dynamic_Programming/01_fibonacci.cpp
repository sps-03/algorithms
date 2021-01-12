/*
FIBONACCI NUMBER:
    Given a number return the number present at that position in the fibonacci series.

    Fibonacci Series is defined as:
         f(0) = 0
         f(1) = 1
         f(n) = f(n-1) + f(n-2), for all n such that: n > 1


    Time Complexity          : O(n)
    Auxiliary Space          : O(n)
*/

#include <iostream>
#include <cstring>
using namespace std;


// helper function for memoization method
int mem_helper(int series[], int num) {
    if(num == 0)    return 0;
    if(num == 1)    return 1;

    if(series[num] == -1)
        series[num] = mem_helper(series, num-1) + mem_helper(series, num-2);

    return series[num];
}

// memoization method
int fib_mem(int num) {
    int series[num+1];
    memset(series, -1, sizeof(series));

    return mem_helper(series, num);
}

// tabular method
int fib_tabular(int num) {
    int series[num+1];
    
    series[0] = 0;
    series[1] = 1;
    for(int i=2; i<=num; i++)
        series[i] = series[i-1] + series[i-2];

    return series[num];
}

int main() {
    int num;
    cout << "Enter the position : ";
    cin >> num;

    cout << "\nFibonacci Number at position " << num << " (memoization method) : " << fib_mem(num);
    cout << "\nFibonacci Number at position " << num << " (tabular method) : " << fib_tabular(num);

    return 0;
}