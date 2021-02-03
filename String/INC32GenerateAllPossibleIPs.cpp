#include <bits/stdc++.h>
using namespace std;

string * restoreIP(string s){
	int n = s.length();
	string ans[];
	if(n<4 or n>12) return ans;
	// DP table is created with 4 rows for the 4 segments
	// for each row we start filling from the last, first
	// contains all the possible occurences of the last 
	// segment of the IP address.
	int dp[4][n];
	for(int i=0;i<4;i++){
		for(int j=n-1;j>=0;j--){
			// If it is the first row, we just fill the
			// upto three lengths from the end as the range
			// is 0-255, so just 3 numbers atmost
			if(i==0){
				string substrng = s.substr(j);
				if(isValid(substrng)) dp[i][j] = 1;
				// This statement means we break when the
				// last segment of the IP is obtained.
				else if(j<n-3) break;
			}else{
				for(int k=1;k<=3 and j+k<n;k++){
					string temp = s.substr(j,k);
					if(isValid(temp)){
						if(dp[i-1][j+k]==1){
							dp[i][j] = 1;
							break;
						}
					}
				}
			}
		}
	}
	if(dp[3][0]==0) return list;
	createIPFromDP(dp,3,0,s,"");
	return list;
}

void createIPFromDP(int dp[][], int r, int c, String s, String ans){


int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string arr[];
		arr = restoreIP(s);
		for(auto s:arr) cout<<s<<endl;
	}
}
