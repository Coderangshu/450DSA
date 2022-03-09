#include<iostream>
using namespace std;
#define MAX 10000
int multiply(int x, int arr[], int asize){
    int carry = 0;
    for(int i=0;i<asize;i++){
        int p = arr[i]*x+carry;
        arr[i] = p%10;
        carry = p/10;
    }
    while(carry){
        arr[asize] = carry%10;
        carry /= 10;
        asize++;
    }
    return asize;
}

void factorial(int n){
    int arr[MAX];
    int asize = 1;
    arr[0] = 1;
    for(int i=2;i<=n;i++) asize = multiply(i,arr,asize);
    for(int i=asize-1;i>=0;i--) cout<<arr[i];
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    factorial(n);
	    cout<<endl;
	}
	return 0;
}
