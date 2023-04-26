// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends

bool isPalindrome(int n){
    int temp = n;
    int rev = 0;
    while(n > 0){
        rev = 10 * rev + n % 10; //take the last digit, and attach with the rev number /= 10;
        n /= 10;
    }
    if(rev == temp) return true;
    return false;
}

/*Complete the function below*/
int PalinArray(int a[], int n)
{  //add code here.
    for(int i=0;i<n;i++) if(!isPalindrome(a[i])) return 0;
    return 1;
}
