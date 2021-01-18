

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

class mergeSort{
        public:
                long long int merger(long long arr[], long long l, long long m, long long r){
                        long long int c=0;
                        int n1 = m-l+1;
                        int n2 = r-m;
                        int L[n1],R[n2];
                        for (int i=0;i<n1;i++) L[i] = arr[l+i];
                        for (int i=0;i<n2;i++) R[i] = arr[m+1+i];
                        int i=0,j=0,k=l;
                        while(i<n1 && j<n2){
                                if(L[i]<=R[j]){
                                        arr[k] = L[i];
                                        i++;
                                }
                                else{
                                        arr[k] = R[j];
                                        j++;
                                        c++;
                                }
                                k++;
                        }
                        while(i<n1){
                                arr[k] = L[i];
                                i++;
                                k++;
                        }
                        while(j<n2){
                                arr[k] = R[j];
                                j++;
                                k++;
                        }
                        return c;
                }

                long long int partitioner(long long arr[], long long l, long long r){
                        long long int c=0;
                        if (l<r){
                            long long m = (r+l-1)/2;
                            c += partitioner(arr,l,m);
                            c += partitioner(arr,m+1,r);
                            c += this->merger(arr,l,m,r);
                        }
                        return c;
                }
};


long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    mergeSort o;
    return o.partitioner(arr,0,N);
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
