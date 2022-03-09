// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000

pair<int,int> findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    rangee = findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

// } Driver Code Ends







// Method: Using min heap we store the first elements of eack k sorted
// arrays while simultaneously storing the max of all of them as the new
// new elements coming will be greater than previous as the arrays are
// sorted, and then keep storing the min from the heap (the min also keeps
// increasing with time), then remove that element heap, calculate the 
// range of max and min if the range is the smallest found till now store 
// this in range and store min in start and max in end, then insert a new
// node into the heap accordingly from that array from which the last node's
// coresponding value was removed, this continues UNTILL ATLEAST ONE OF THE
// ARRAY IS COMPLETED, so by this time we will have checked atleast some numbers
// from each of the k arrays








// you are required to complete this function 
// function should print the required range

struct MinHeapNode {
    int element;
    int i;
    int iNext;
};


void swapNode(MinHeapNode *x, MinHeapNode *y){
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap{
    // Pointer to heap array
    MinHeapNode *hparr;
    // size of heap array
    int heap_size;
public:    
    
    // Recursive heapifier
    void MinHeapify(int i){
        int l = 2*i+1;
        int r = 2*i+2;
        int smallest = i;
        if(l<heap_size and hparr[l].element<hparr[smallest].element) smallest = l;
        if(r<heap_size and hparr[r].element<hparr[smallest].element) smallest = r;
        if(smallest!=i){
            swapNode(&hparr[i],&hparr[smallest]);
            MinHeapify(smallest);
        }
    }
    
    // Constructor of heap
    MinHeap(MinHeapNode arr[], int size){
        this->heap_size = size;
        this->hparr = arr;
        int lnln = (heap_size-1)/2;
        while(lnln>=0){
            MinHeapify(lnln);
            lnln--;
        }
    }
    
    // Get the min heapNode from the heap
    MinHeapNode getMin(){ return hparr[0];}
    
    // Replace the smallest heapNode with new element from the k arrays
    void replaceMin(MinHeapNode x){
        hparr[0] = x;
        // Min heapify from the starting index again
        MinHeapify(0);
    }
};

pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
    //code here
    
    // Range stores the smallest range found till now
    int range = INT_MAX;
    // min and max stores the min and max obtained till now
    int min = INT_MAX, max = INT_MIN;
    // start and end stores the final start and end of range
    int start, end;
    
    // Create array of MinHeapNode of size k, each heap node
    // contains the 1st element of each sorted array
    MinHeapNode *harr = new MinHeapNode[k];
    for(int i=0;i<k;i++){
        // Store first element of ith array
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].iNext = 1;
        // store max element
        if (harr[i].element > max)
            max = harr[i].element;
    }
    
    // Create heap of harr
    MinHeap mhps(harr,k);
    
    // Now one by one get the minimum element from min
    // heap and replace it with next element of its list
    while (1) {
        // Get the minimum element and store it in output
        MinHeapNode root = mhps.getMin();
 
        // update min
        min = mhps.getMin().element;
 
        // update range
        if (range > max - min + 1) {
            range = max - min + 1;
            start = min;
            end = max;
        }
        
        // Find the next element that will replace current
        // root of heap. The next element belongs to same
        // list as the current root.
        if (root.iNext < N) {
            root.element = arr[root.i][root.iNext];
            root.iNext += 1;
 
            // update max element
            if (root.element > max)
                max = root.element;
        }
 
        // break if we have reached end of any list
        else
            break;
 
        // Replace root with next element of list
        mhps.replaceMin(root);
    }
    return make_pair(start,end);
}

// Same as above using priority queue

/*
Summary of algorithm :
Target is : minHeap will contain smallest element of range and max variable keeps track of max
Procedure :
we create minHeap for size k, taking all first elements of each sorted list
also keeping track of the max of all inserted in max variable

iterate minHeap until its empty
get minHeap top (this is the smallest element)
update smallest range to max - minHeap.top() + 1, if it is less than current smallest range
push into heap the next element of the same list from which the current minHeap.top() was popped
also check this new pushed element with max to update the max variable
break while loop if any of the list ends as then we won't have common element from all the lists
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mn, mx = INT_MIN, n = nums.size();
        vector<int> indices(n,0);
        // minHeap pair contains {element of list,list serial number corresponding to the element}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(int i=0;i<n;i++){
            minHeap.push({nums[i][0],i});
            mx = max(mx,nums[i][0]);
        }
        vector<int> ans;
        int diff = INT_MAX;
        while(!minHeap.empty()){
            auto [n,i] = minHeap.top();
            minHeap.pop();
            mn = n;
            if(mx-mn<diff){
                diff = mx-mn;
                ans = {mn,mx};
            }
            if(++indices[i]>=nums[i].size()) break;
            mx = max(mx,nums[i][indices[i]]);
            minHeap.push({nums[i][indices[i]],i});
        }
        return ans;
    }
};