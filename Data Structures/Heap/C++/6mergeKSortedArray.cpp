#include <bits/stdc++.h>
using namespace std;

// Customized heap node
struct MinHeapNode{
    // The element to be stored
    int element;
    // The index of array from which element is taken
    int i;
    // Index of element that is to be taken next
    int iNext;
};

// To swap MinHeapNode
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

// Merge the k sorted arrays
// its input is an array of size k, with each
// array being of size n
vector<int> mergeKArrays(vector<vector<int>> arr, int k){
    vector<int> ans;
    int n = arr[0].size();
    // Create array of MinHeapNode of size k
    MinHeapNode *harr = new MinHeapNode[k];
    for(int i=0;i<k;i++){
        // Store first element of ith array
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].iNext = 1;
    }
    // Create heap of harr
    MinHeap mhps(harr,k);
    
    // Now we get each least element from the heap and
    // store it in our final vector and replace it with 
    // the next element(i.e. the element removed from the
    // heap is replaced by the element from the same array
    // which is kept track of by the MinHeapNode.i)
    for(int  count = 0; count<n*k;count++){
        // Get min value from heap and store in ans
        MinHeapNode minVal = mhps.getMin();
        ans.push_back(minVal.element);
        
        // Find the next element that will replace current
        // root of heap. The next element belongs to same
        // array as the current minVal.
        if(minVal.iNext<n){
            minVal.element = arr[minVal.i][minVal.iNext];
            minVal.iNext += 1;
        }
        // If minVal was the last element of its array
        // INT_MAX is for infinite       
        else minVal.element =  INT_MAX;
        // Replace minVal with next element
        mhps.replaceMin(minVal);
    }
    return ans;
}

int main()
{
    // Change n at the top to change number of elements
    // in an array
    int n = 4;
    vector<vector<int>> arr =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = 3;
 
    vector<int> ans = mergeKArrays(arr,k);
 
    cout << "Merged array is " << endl;
    for(auto e:ans) cout<<e<<" ";
 
    return 0;
}
