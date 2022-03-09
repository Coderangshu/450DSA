#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    
    vector<string> ans;
    
    void backtracking(string s, int ind, string pip, int part){
        int n = s.length();
        if(part==4 and ind==n){
            ans.push_back(pip.substr(1));
            return;
        }
        if(part==4 or ind==n) return;
        string ipart = "";
        int intpart = 0;
        for(int i=ind;i<ind+3;i++){
            ipart += s[i];
            intpart = 10*intpart+(s[i]-'0');
            if(ipart[0]=='0' and ipart.length()>1) return;
            if(intpart>255) return;
            if(intpart>=0 and intpart<=255) backtracking(s,i+1,pip+'.'+ipart,part+1);
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        backtracking(s,0,"",0);
        return ans;
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		Solution obj = Solution();
		vector<string> arr = obj.restoreIpAddresses(s);
		for(auto s:arr) cout<<s<<endl;
	}
}
