        // sending k-1 because k is 1 indexed but we need o indexed

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    // Brute Force: Use array of size m+n and store all sorted then return kth element
    // Time complexity: O(n+m) Space complexity : O(n+m)
    
    // Better Approach: traverse both array with 2 pointers and keep track of kth smallest
    // when reached return that element
    // Time complexity: O(k) Space complexity : O(1)
    
    // Best Approach (Modified binary search): https://www.youtube.com/watch?v=nv7F4PiLUzo
    // we binary search for the cut on array such that all elements left of cut and the rest elements
    // from the other array are lesser than the right of cut and all the other remaininig elements
    // of the other array, then the kth element will be the max of the last element left of cut
    // and the last element of the elements taken from the other array, see video for better
    // understanding
    // Time complexity: O(log(min(n,m))) Space complexity : O(1)
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // swapping the arrays to keep the lower size one first
        // as we will search for the cut in the first array thus
        // keeping its size low will give lesser time complexity
        // thus O(log(min(n,m))) 
        if(n>m) return kthElement(arr2,arr1,m,n,k);
        
        // low can be 0 or if m is lesser than k than atleast k-m elements from
        // arr1 has to be taken
        // high can be n or if there are more than k elements in it then only k can
        // be taken
        int low = max(0,k-m), high = min(n,k);
        
        while(low<=high){
            // taking mid of low and high as the cut1, i.e. cut1 number of elements
            // taken from arr1 into the left section
            int cut1 = (low+high)>>1;
            // rest k-cut1 elements are taken into the left section from arr2
            int cut2 = k-cut1;
            
            // taking the left and right of cut's values for both arrs
            // also handling the cases when cut is at 0 or at end
            int l1 = (cut1==0)?INT_MIN:arr1[cut1-1];
            int r1 = (cut1==n)?INT_MAX:arr1[cut1];
            int l2 = (cut2==0)?INT_MIN:arr2[cut2-1];
            int r2 = (cut2==m)?INT_MAX:arr2[cut2];
            
            // if all of left section are lesser than all of right section
            // than return max of left section as left section always contains
            // k values thus max of left will be the kth element
            if(l1<=r2 and l2<=r1) return max(l1,l2);
            // l1 > r2 means that some elements from arr1 need to be shifted to
            // right section thus the cut1 is to be leftward thus it is to be searched
            // in the lower half of low to high
            else if(l1>r2) high = cut1-1;
            // else cut1 is to be shifted right thus search in higher half
            else low = cut1+1;
        }
        // reaches here if array aren't sorted
        return -1;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends
