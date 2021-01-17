#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        int e;
	        cin>>e;
	        arr[i] = e;
	    }
	    cin>>m;
	    sort(arr,arr+n);
	    int mn = INT_MAX;
	    for(int i=0;i<(n-m)+1;i++){
	        if(arr[i+(m-1)]-arr[i]<mn) mn = arr[i+(m-1)]-arr[i];
	    }
	    cout<<mn<<endl;
	}
	return 0;
}
