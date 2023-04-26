// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
      
      
    // using Binary indexed tree (Fenwick Tree)
      
    // fenwick tree array
    vector<int> fenwick;
      
    // function to add number to ith place of tree and
    // also update those values which contain the ith element
    // sum in them
    void updateSum(int i, int number){
        int n = fenwick.size();
        while(i<n){
            fenwick[i] += number;
            // getting the next index which has this current index(bit)
            // in it
            // to get the next bit which contains the current bit
            // -i = 2's complement (a1b -> a'1b) b is all 0, this is obtained
            // from i'+1 ((a1b)'+1 -> a'0b'+1 -> a1b) 
            // at starting b is all 0 as the 1 in between is the right most set bit
            // on complementing the last set bit becomes 0 and b all becomes 1 and
            // a get complemented, on adding 1 to it all b becomes 0 again and the
            // right most set bit becomes 1 and the a remains complement
            // i&(-i) = right most set bit (a1b&a'1b -> 1b) b is all 0
            // adding the right most set bit to i gives the next bit which contains
            // i in it, continue until in range of tree
            i += (i&(-i));
        }
    }
      
    // function to find sum upto ith index
    int getSum(int i){
        int sum = 0;
        while(i>0){
            sum += fenwick[i];
            i -= (i&(-i));
        }
        return sum;
    }
      
      
      
      
      
    // we use merge sort to count the number of inversions 
    
    void merge(long long arr[], int start, int mid, int end, long long int &count){
        int n1 = mid-start+1, n2 = end-mid;
        long long t1[n1], t2[n2];
        for(int i=0;i<n1;i++) t1[i] = arr[start+i];
        for(int i=0;i<n2;i++) t2[i] = arr[mid+1+i];
        int i = start, a1 = 0, a2 = 0;
        while(a1<n1 and a2<n2){
            if(t1[a1]>t2[a2]){
                // when the left array has element greater than right
                // then we need inverse all the elements next to the
                // current element in left to get the correct element
                // (the smaller right sub array element) thus the count
                // increases by that #, the number is:
                // the mid - the greater element index in left sub array
                count += (mid+1)-(start+a1);
                arr[i++] = t2[a2++];
            }
            else arr[i++] = t1[a1++];
        }
        while(a1<n1) arr[i++] = t1[a1++];
        while(a2<n2) arr[i++] = t2[a2++];
    }
    
    void mergeSort(long long arr[], int start, int end, long long int &count){
        if(start>=end) return;
        int mid = (start+end)>>1;
        mergeSort(arr,start,mid,count);
        mergeSort(arr,mid+1,end,count);
        merge(arr,start,mid,end,count);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int count = 0;
        
        // using binary indexed tree also the same above can be done
        // but here just the demonstration of the fenwick tree is given
        // this functions to store the sum upto ith index and also update
        // the sum at ith index in logN time
        
        // initializing fenwick tree vector
        // fenwick tree uses 1 indexed thus size is N+1
        fenwick.assign(N+1,0);
        
        // for each arr[i] we update the value in fenwick tree
        // update here means we add arr[i] to the fenwick tree
        for(int i=0;i<N;i++) updateSum(i+1,arr[i]);
        // printing the fenwick tree
        for(auto e:fenwick) cout<<e<<" ";
        cout<<endl;
        // getting sum upto index 2
        cout<<getSum(3)<<endl;
        
        // using mergeSort to count the inversions
        mergeSort(arr,0,N-1,count);
        return count;
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
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
