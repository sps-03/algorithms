/*
JOB SEQUENCING:
    Given a set of jobs where each job is having a deadline and profit associated with it.
    To get the profit the job needs to be finished before the corresponding deadline.
    Every job takes single unit of time, so the minimum possible deadline for any job is 1.
    We need to find the optimal job sequence such that total profit will be maximum.
    (note: only one job can be scheduled at a time)

    Here we will use the Greedy approach.
    First sort the jobs in decreasing order of profit then iterate through each of them.
    For each job find the greatest time slot i, such that the slot is empty and i < deadline.
    If we get such slot mark it filled, else if no such slot exists then ignore the job.

    Time Complexity          : O(n*n)
    Auxiliary Space          : O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;


struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n) {
    sort(arr, arr+n, compare);      // sort all jobs according to decreasing order of the profit

    int maxprofit = 0;                    // to store maximum profit value we can get
    char result[n];                       // to store result (sequence of jobs)
    bool slot[n];                         // to keep track of time slots

    for(int i=0; i<n; i++)                // initialize all slots to be free
        slot[i] = false;

    for(int i=0; i<n; i++) {              // iterate through each job
       for(int j=min(n, arr[i].deadline)-1; j>=0; j--) {   // find greatest free slot possible
          if(slot[j]==false) {            // if free slot found
             result[j] = arr[i].id;       // add this job to result
             slot[j] = true;              // make the slot occupied
             maxprofit += arr[i].profit;  // add this profit
             break;
          }
       }
    }

    cout << "Sequence : ";
    for(int i=0; i<n; i++)
       if(slot[i]) cout << result[i] << " ";
    cout << "\nProfit : " << maxprofit << "\n";
}

int main() {
    Job arr[] = {{'a', 3, 20}, {'b', 2, 30}, {'c', 3, 60},
                 {'d', 1, 15}, {'e', 4, 15}, {'f', 2, 25}};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Optimal job sequence and profit is given below:\n";
    printJobScheduling(arr, n);

    return 0;
}