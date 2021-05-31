// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution
{
    public:
    
    // Method: Median is the middle of a sorted array
    // We maintain 2 heaps one min one max, the max is
    // in the left of the median and min on the right
    // in max is the elements left of median and sane
    // for counterpart right. Now we need not sort the
    // complete array on both side thus we use heap to
    // keep track of the max of all in left using maxHeap
    // and min of all in right using minHeap.
    // Now if both have same number of values after insertion
    // and balancing then the median is average of the max of
    // left and min of right.
    // Else when one of the heap has one element more than other
    // then that extra element (either max of left or min of right
    // is the median as it will reside in the middle of the sorted
    // array.
    
    
    
    // left max heap
    priority_queue<int,vector<int>> maxHeap;
    // right min heap
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int input;
    // initial median
    double median = 0;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        // x is the element given in stream
        input = x;
        getMedian(); 
    }
    
    //Function to balance heaps.
    void balanceHeaps(int ltr, int input)
    {
        // When leftToRight(ltr) is 1 means that
        // maxHeap is larger and the input is
        // smaller than the current median, thus the
        // max of maxHeap needs to be shifted to the
        // right(i.e. minHeap) and then the new element
        // is inserted into the maxHeap, thus keeping
        // both the heaps balanced
        if(ltr==1){
            int toBePoped = maxHeap.top();
            maxHeap.pop();
            minHeap.push(toBePoped);
            maxHeap.push(input);
        }
        // When ltr is 0 means size(minHeap)>size(maxHeap)
        // and input is larger than current median thus
        // again shifting occurs and input inserted
        else{
            int toBePoped = minHeap.top();
            minHeap.pop();
            maxHeap.push(toBePoped);
            minHeap.push(input);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        int lc = maxHeap.size();
        int rc = minHeap.size();
        int diff = lc-rc;
        // When both heaps are equal
        if(diff==0){
            // when input is smaller than current median
            // input pushed into maxHeap and the median is
            // updated(change might happen or not happen)
            // to the max of maxHeap
            if(input<median){
                maxHeap.push(input);
                median = maxHeap.top();
            }
            // when input is larger than current median
            // similar strategy is followed
            else{
                minHeap.push(input);
                median = minHeap.top();
            }
        }
        // when left heap(maxHeap) is larger than right
        // after balancing both heap have same number of
        // values thus the median is updated to the average
        // of max of max heap and min of min heap
        else if(diff==1){
            if(input<median) balanceHeaps(1,input);
            else minHeap.push(input);
            median = (maxHeap.top()+minHeap.top())/2;
        }
        // when right heap(minHeap) is larger similar
        // strategy is followed
        else{
            if(input>median) balanceHeaps(0,input);
            else maxHeap.push(input);
            median = (maxHeap.top()+minHeap.top())/2;
        }
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends
