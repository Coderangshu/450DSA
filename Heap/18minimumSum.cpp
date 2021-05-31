// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    void heapify(int arr[],int index, int size){
        int smallest = index;
        int l = 2*index+1;
        int r = 2*index+2;
        if(l<size and arr[l]<arr[smallest]) smallest = l;
        if(r<size and arr[r]<arr[smallest]) smallest = r;
        if(smallest!=index){
            swap(arr[smallest],arr[index]);
            heapify(arr,smallest,size);
        }
    }
    
    void buildHeap(int arr[], int size){
        for(int i=size/2-1;i>=0;i--)
            heapify(arr,i,size);
    }
    
    string solve(int arr[], int n) {
        // code here
        if(n==1) return to_string(arr[0]);
        buildHeap(arr,n);
        long long int n1 = 0, n2 = 0;
        long long int i = 0, last = n-1;
        // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        // cout<<endl;
        while(i<n){
            // Take the first and second digits of minHeap
            // i.e. the smallest and the second smallest
            // put each in two of the number and then proceed
            // the same after heapifying after each step
            n1 = n1*10+arr[0];
            swap(arr[last],arr[0]);
            heapify(arr,0,last--);
            if(i<n){
                n2 = n2*10+arr[0];
                swap(arr[last],arr[0]);
                // last=1(occurs when n is odd) means that
                // only one element left in unsorted heap,
                // assign that to n1 and break the loop
                if(last==1){
                    n1 = n1*10+arr[0];
                    break;
                }
                heapify(arr,0,last--);
            }
            i += 2;
        }
        // cout<<n1+n2<<endl;
        return to_string(n1+n2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
