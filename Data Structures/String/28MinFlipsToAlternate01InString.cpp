
#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int ans = 0, n = s.length();
		// considering the first character as 0
		// finding the # of flips
	    for(int i=0;i<n;i++){
	        if(i%2==0 and s[i]=='1') ans++;
	        if(i%2==1 and s[i]=='0') ans++;
	    }
		// returning the min of when first character is
		// 0 and when first character is 1
	    cout<<min(ans,n-ans)<<endl;
	}
	return 0;
}
