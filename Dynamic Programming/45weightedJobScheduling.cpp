#include<bits/stdc++.h>
using namespace std;

// A job has start time, finish time and profit.
struct Job{
    int start, finish, profit;
};

// A utility function that is used for sorting events
// according to finish time
bool jobComparator(Job s1, Job s2){
    return (s1.finish < s2.finish);
}

bool jobComparatorLIS(Job s1, Job s2){
    return (s1.start>s2.start);
}

// Utility function to calculate sum of all vector
// elements while using the LIS method
int findSum(vector<Job> arr){
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum +=  arr[i].profit;
    return sum;
}




// For searching use either latestNonConflict or latestNonConflictBS
// the later searches in nlogn time and the former does the same in
// n time


// Find the latest job (in sorted array) that doesn't
// conflict with the job[i]. If there is no compatible job,
// then it returns -1.
int latestNonConflict(Job arr[], int i){
    for (int j=i-2; j>=0; j--)
        if (arr[j].finish <= arr[i-1].start)
            return j;
    return -1;
}

// finding the latest job(in sorted array) that doesn't
// overlap using binary search thus decreasing the search
// time from O(n) to O(nlogn)
int latestNonConflictBS(Job arr[], int i){
    int start = 0, end = i-2;
    int ans=-1;
    while(start<end){
        int mid = start+(end-start)/2;
        if(arr[mid].finish<=arr[i-1].start){
            ans = mid;
            start = mid+1;
        }
        else end = mid;
    }
    return ans;
}







// Recursive approach


// A recursive function that returns the maximum possible
// profit from given array of jobs.  The array of jobs must
// be sorted according to finish time.
int findMaxProfitRec(Job arr[], int n){
    // Base case
    if (n == 1) return arr[n-1].profit;

    // we got 2 choices either take the current interval
    // or reject it

    // Find profit when current job is included
    int inclProf = arr[n-1].profit;

    // finding for the most latest non overlapping
    // interval previous to the current interval
    int i = latestNonConflict(arr, n);

    // if suitable interval found recur for that interval
    if (i != -1)
      inclProf += findMaxProfitRec(arr, i+1);

    // Find profit when current job is excluded
    int exclProf = findMaxProfitRec(arr, n-1);

    return max(inclProf,exclProf);
}



// Memoization approach

int memo[1001];
int findMaxProfitMem(Job arr[], int n){
    // Base case
    if (n == 1) return memo[n] = arr[n-1].profit;

    // if present in memo
    if(memo[n]!=-1) return memo[n];

    // we got 2 choices either take the current interval
    // or reject it

    // Find profit when current job is included
    int inclProf = arr[n-1].profit;

    // finding for the most latest non overlapping
    // interval previous to the current interval
    int i = latestNonConflictBS(arr, n);

    // if suitable interval found recur for that interval
    if (i != -1)
      inclProf += findMaxProfitMem(arr, i+1);

    // Find profit when current job is excluded
    int exclProf = findMaxProfitMem(arr, n-1);

    return memo[n] = max(inclProf,exclProf);
}

// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit(Job arr[], int n){
    // Sort jobs according to finish time
    sort(arr, arr+n, jobComparator);
    // return findMaxProfitRec(arr,n);

    memset(memo,-1,sizeof(memo));
    return findMaxProfitMem(arr,n);
}




// Using modified LIS (no searching required)
void findMaxProfitLIS(vector<Job> arr){
    // Sort arr[] by start time.
    sort(arr.begin(), arr.end(), jobComparatorLIS);

    // L[i] stores Weighted Job Scheduling of
    // job[0..i] that ends with job[i]
    vector<vector<Job>> L(arr.size());

    // L[0] is equal to arr[0]
    L[0].push_back(arr[0]);

    // start from index 1
    for (int i = 1; i < arr.size(); i++){
        // for every j less than i
        for (int j = 0; j < i; j++){
            // L[i] = {MaxSum(L[j])} + arr[i] where j < i
            // and arr[j].finish <= arr[i].start
            if ((arr[j].finish <= arr[i].start) &&
                (findSum(L[j]) > findSum(L[i])))
                L[i] = L[j];
        }
        L[i].push_back(arr[i]);
    }

    vector<Job> maxChain;

    // find one with max profit
    for (int i = 0; i < L.size(); i++)
        if (findSum(L[i]) > findSum(maxChain))
            maxChain = L[i];

    for (int i = 0; i < maxChain.size(); i++)
        cout << "(" <<  maxChain[i].start << ", " <<
             maxChain[i].finish << ", "
             <<  maxChain[i].profit << ") ";
}


// Driver program
int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    vector<Job> a = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr,n);
    findMaxProfitLIS(a);
    return 0;
}
