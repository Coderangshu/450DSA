#include <bits/stdc++.h>
using namespace std;

// TC : O((n-k)*k*klogk)
class Solution{
    private:
    void heapify(int arr[], int i, int n){
        if(i>n) return;
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l<n and arr[l]>arr[largest]) largest = l;
        if(r<n and arr[r]>arr[largest]) largest = r;
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }
    }

    void buildHeap(int arr[], int size){
        // Last non leaf node
        int lnln = size/2-1;
        for(int i=lnln;i>=0;i--){
            heapify(arr,i,size);
        }
    }

    public:
    vector<int> getMaxK(int arr[], int n, int k){
        int sliding_window[k];
        vector<int> ans;
        for(int i=0;i<=n-k;i++){
            // filling each element of window s
            for(int j=i;j<k+i;j++){
                sliding_window[j-i] = arr[j];
            }
            buildHeap(sliding_window,k);
            ans.push_back(sliding_window[0]);
        }
        return ans;
    }
};

// TC : O(n)
class Solution1{
    public:
    vector<int> getMaxK(int arr[], int n, int k){
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!q.empty() and (q.front()<=i-k or arr[i]>=arr[q.front()])) q.pop();
            q.push(i);
            if(i>=k-1) ans.push_back(arr[q.front()]);
        }
        return ans;
    }
};

int main(){
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = 9, k = 3;
    Solution obj;
    Solution1 obj1;
    for(int i:obj.getMaxK(arr,n,k)) cout<<i<<" ";
    cout<<endl;
    for(int i:obj1.getMaxK(arr,n,k)) cout<<i<<" ";
    return 0;
    
}
