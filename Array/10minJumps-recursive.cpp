#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
    if(n==1) return 0;
    int mj = INT_MAX;
    for(int i=n-2;i>=0;i--){
        if(i+arr[i]>=n-1){
            int j = minJumps(arr,i+1);
            mj = min(mj,j+1);
        }
    }
    return mj;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
