
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
	    int start0 = 0, start1 = 0;
	    for(int i=0;i<s.length();i++){
	        if(i%2==0){
	            if(s[i]=='0') start1++;
	            else start0++;
	        }
	        else{
	            if(s[i]=='1') start1++;
	            else start0++;
	        }
	    }
	    cout<<min(start0,start1)<<endl;
	}
	return 0;
}
