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

// Using sorting
class Solution1{
public:
    int solve(int arr[], int n){
        sort(arr,arr+n);
        int i = 0, n1 = 0, n2 = 0;
        while(i<n){
            if(i+1>=n){
                if(n1<=n2) n1 = 10*n1+arr[i];
                else n2 = 10*n2+arr[i];
            }
            else{
                n1 = 10*n1+arr[i];
                n2 = 10*n2+arr[i+1];
            }
            i += 2;
        }
        cout<<n1<<" "<<n2<<endl;
        return n1+n2;
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
        cout<<ob.solve(arr, n)<<endl;
        Solution1 ob1;
        cout<<ob1.solve(arr, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends

// same as above using STL

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int i = 0;
        while(i<n)
            minHeap.push(arr[i++]);
        long long int n1 = 0, n2 = 0;
        while(!minHeap.empty()) {
            n1 = 10*n1 + minHeap.top();
            minHeap.pop();
            if(!minHeap.empty()) {
                n2 = 10*n2 + minHeap.top();
                minHeap.pop();
            }
        }
        return to_string(n1+n2);
    }
};