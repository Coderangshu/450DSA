// CPP program to find the k-th largest sum
// of subarray
#include <bits/stdc++.h>
using namespace std;

// function to calculate kth largest element
// in contiguous subarray sum
int kthLargestSum(int arr[], int n, int k)
{
    
    // The methodology to calculate the sums of the subarrays,
    // lets understand using as example
    // let array {6,8,3,7,5,6,4} of length n
    // we calculate an array sum of length n+1 which has the
    // prefix value prefix value at ith cell means the sum
    // of the array taking the first i numbers. Thus sum array
    // of above is : {0,6,14,17,24,29,35,39}
    // Now for getting the sum of subarray from ith position to 
    // jth position we have the answer as sum[j]-sum[i-1]
    // lets check for some values:
    // (I)  i = 1 and j = 3, we know answer = 6+8+3 = 17 using
    //      prefix array we have 17-0 = 17
    // (II) i = 2 and j = 5, we know answer = 8+3+7+5 = 23 using
    //      prefix array we have 29-6=23


    
    // Then we use priority queue to calculate the min heap and 
    // find the k th largest sum of these sums

    
    
	// array to store prefix sums
	int sum[n + 1];
	sum[0] = 0;
	sum[1] = arr[0];
	for (int i = 2; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i - 1];

    // the priority queue stores the k largest sums of the total subarray sums
    // so we calculate each sum and then insert it into the queue, inside it
    // after each insertion it performs min heapify thus the elements inside it
    // are always sorted ascending order, with the top pointing to the smallest
    // now when filled upto kth element we check the smallest(i.e. top) element
    // in queue with the new sums, if new sum is greater than the top we know
    // that queue doesn't have the k largest element so we pop the top and push
    // the new sum and the queue sorts itself, this continues until all the sums
    // are exhausted, and at last we end up with the queue having k elements that
    // are the largest sums of all the sub array sums which is sorted ascendingly
    // thus the first element(i.e. the smallest/top) would be the kth largest
    // sum of all.
    
	// priority_queue of min heap
	priority_queue<int, vector<int>, greater<int> > Q;

	// loop to calculate the contiguous subarray
	// sum position-wise
	for (int i = 1; i <= n; i++)
	{
		// loop to traverse all positions that
		// form contiguous subarray
		for (int j = i; j <= n; j++){
			// calculates the contiguous subarray
			// sum from ith positon to jth position
			int x = sum[j] - sum[i - 1];
            
			// if queue has less then k elements,
			// then simply push it
			if (Q.size() < k) Q.push(x);
            
			else{
				// it the min heap has equal to
				// k elements then just check
				// if the largest kth element is
				// smaller than x then insert
				// else its of no use
				if (Q.top() < x){
					Q.pop();
					Q.push(x);
				}
			}
		}
	}

	// the top element will be then kth
	// largest element
	return Q.top();
}

// Driver program to test above function
int main()
{
	int a[] = { 10, -10, 20, -40 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 6;

	// calls the function to find out the
	// k-th largest sum
    int ans = kthLargestSum(a, n, k);
	cout << endl<< ans;
	return 0;
}

