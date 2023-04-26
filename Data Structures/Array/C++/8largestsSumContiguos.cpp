#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    int max_so_far = arr[0], max_ending_here = arr[0];
    for (int i = 1; i < n; i++){
        max_ending_here = max(max_ending_here+arr[i],arr[i]);
        max_so_far = max(max_ending_here,max_so_far);
    }
    return max_so_far;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout << maxSubarraySum(a, n) << endl;
    }
}
