// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    // merging in place means space complexity O(1)
    // TC : O(n^2)
    // Method : when large element found in left subarray, sweep 
    // all to one right and store the smaller element of right subarray
    // in the place of the left subarray
    void mergeNSqr(long long arr[], int start, int mid, int end){
        int n1 = mid-start+1, n2 = end-mid;
        int a1 = start, a2 = mid+1;
        while(a1<=mid and a2<=end){
            // when first part got bigger # store a2 element and
            // right shift all from a1 to a2 index, this makes a1
            // index empty place a2's element there
            if(arr[a1]>arr[a2]){
                long long num = arr[a2];
                int index = a2++;
                while(index>a1){
                    arr[index] = arr[index-1];
                    index--;
                }
                arr[a1++] = num;
                // as the left sub array has shifted thus its
                // ending point also shift by 1
                mid++;
            }
            // else its already sorted try the next element
            // of left sub array
            else a1++;
        }
    }
    
    
    
    // TC : O(logn*nlogn) (logn for all recursive calls and merge function
    // takes nlog n time to sort and merge 2 subarrays
    // Method : Use kind of shell sort
    // Example:
    // Input: 10, 30, 14, 11, 16, 7, 28

    // Note: Assume left and right subarrays has been sorted 
    // so we are merging sorted subarrays [10, 14, 30] and [7, 11, 16, 28]


    //     Start with
    // 
    //     gap =  ceiling of n/2 = 7/2 = 4
    // 
    //     [This gap is for whole merged array]
    //     In quote elements represents the elements
    //     under consideration in current iteration
    // 
    //     '10', 14, 30, 7, '11', 16, 28
    // 
    //     10, '14', 30, 7, 11, '16', 28
    // 
    //     10, 14, '30', 7, 11, 16, '28'
    // 
    //     10, 14, 28, 7, 11, 16, 30
    //     
    //     
    // 
    //     gap =  ceiling of 4/2 = 2
    // 
    //     '10', 14, '28', 7, 11, 16, 30
    // 
    //     10, '14', 28, '7', 11, 16, 30
    // 
    //     10, 7, '28', 14, '11', 16, 30
    // 
    //     10, 7, 11, '14', 28, '16', 30
    // 
    //     10, 7, 11, 14, '28', 16, '30'
    // 
    //      
    // 
    //     gap =  ceiling of 2/2 = 1
    // 
    //     '10', '7', 11, 14, 28, 16, 30
    // 
    //     7, '10', '11', 14, 28, 16, 30
    // 
    //     7, 10, '11', '14', 28, 16, 30
    // 
    //     7, 10, 11, '14', '28', 16, 30
    // 
    //     7, 10, 11, 14, '28', '16', 30
    //     
    //     7, 10, 11, 14, 16, '28', '30'

     

    Output: 7, 10, 11, 14, 16, 28, 30
    // returns the ceiling of gap/2 as the next gap
    int gapBy2(int gap){
        if(gap<=1) return 0;
        return (int)ceil(gap/2.0);
    }
    
    void mergeShellSort(long long arr[], int start, int end){
        int gap = end-start+1;
        for(gap=gapBy2(gap);gap>0;gap=gapBy2(gap)){
            for(int i=start;i+gap<=end;i++){
                int j = i+gap;
                cout<<arr[i]<<" "<<arr[j]<<endl;
                if(arr[i]>arr[j]) swap(arr[i],arr[j]);
            }
        }
    }
    
    void mergeSort(long long arr[], int start, int end){
        if(start>=end) return;
        int mid = (start+end)>>1;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
//         mergeNSqr(arr,start,mid,end);
        mergeShellSort(arr,start,end);
    }
    
    void mergeSortInPlace(long long arr[], long long N)
    {
        // Your Code Here
        mergeSort(arr,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        obj.mergeSortInPlace(A,N);
        for(int i=0;i<N;i++) cout<<A[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}
  // } Driver Code Ends
