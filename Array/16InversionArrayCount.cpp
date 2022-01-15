

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

class mergeSort{
        public:
        long long merger(long long arr[], long long l, long long m, long long r){
                long long n1 = m-l, n2 = r-m+1, c = 0;
                long long la[n1], ra[n2];
                for(long long i=0;i<n1;i++) la[i] = arr[l+i];
                for(long long i=0;i<n2;i++) ra[i] = arr[m+i];
                long long i = 0, j = 0, k = l;
                while(i<n1 and j<n2){
                        if(la[i]>ra[j]){
                                arr[k++] = ra[j++];
                                // adding # of swaps that are
                                // being done in this point
                                c += m-(i+l);
                        }
                        else arr[k++] = la[i++];
                }
                while(i<n1) arr[k++] = la[i++];
                while(j<n2) arr[k++] = ra[j++];
                return c;
        }
    
        long long partitioner(long long arr[], long long l, long long r){
                long long c = 0;
                if(l<r){
                long long m  = (r+l)>>1;
                c += partitioner(arr,l,m);
                c += partitioner(arr,m+1,r);
                c += merger(arr,l,m+1,r);
                }
                return c;
        }
        
        long long int inversionCount(long long arr[], long long N)
        {
                // Your Code Here
                long long ans = partitioner(arr,0,N-1);
                // for(int i=0;i<N;i++) cout<<arr[i]<<" ";
                // cout<<endl;
                return ans;
        }
};


long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    mergeSort o;
    return o.partitioner(arr,0,N-1);
}


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
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
