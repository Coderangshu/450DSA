// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<sb(a,n,x)<<endl;
	}
	return 0;
}// } Driver Code Ends




int sb(int arr[], int n, int x)
{
    // Your code goes here
    int sum=0,start=0,end=0;
    int min_len = n+1;
    while(end<n){
        while(sum<=x && end<n) sum += arr[end++];
        while(sum>x && start<n){
            if(end-start<min_len) min_len = end-start;
            sum -= arr[start++];
        }
    }
    return min_len;
}
