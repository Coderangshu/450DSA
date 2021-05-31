#include <bits/stdc++.h>
using namespace std;

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

int main(){
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
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
    for(int i:ans) cout<<i<<" ";
    return 0;
}
