#include<bits/stdc++.h>
using namespace std;

long swapCount(string s){
    int ans = 0, n = s.length();
    // stores the index of all the open brackets
    vector<int> openIdx;
    for(int i=0;i<n;i++) if(s[i]=='[') openIdx.push_back(i);

    // keeps track of balance of brackets:
    // (1) <0 -> more closing brackets
    // (2) >0 -> more opening brackets
    // (3) =0 -> balanced
    // oi keeps track of the index in openIdx that has been already used
    int balanceCounter = 0, oi = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='['){
            balanceCounter++;
            // 1 open bracket used up thus move to next in openIdx
            oi++;
        }
        else{
            balanceCounter--;
            // if balanceCounter <0 implies more closing brackets than opening
            // thus need to balance
            if(balanceCounter<0){
                // number of swaps required would be the diff of next open bracket
                // and current index of the closing bracket
                ans += openIdx[oi]-i;
                // swapping directly to make the correction
                swap(s[openIdx[oi]],s[i]);
                cout<<s<<" "<<ans<<endl;
                // 1 open bracket used up thus move to next in openIdx
                oi++;
                // now its balanced upto ith index
                balanceCounter = 1;
            }
        }
        // if oi is out of bounds then all the open brackets have been used
        if(openIdx.size()==oi) break;
    }
    return ans;
}

long swapCount1(string s){
    int open = 0, close = 0, fault = 0, n = s.length(), ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]==']'){
            close++;
            fault = close-open;
        }
        else{
            open++;
            // we obtained a opening bracket
            // now if there's a fault from previous then
            // we adjust it with this opening bracket
            if(fault>0){
                // # of swaps required is the fault
                ans += fault;
                // one fault has been corrected
                fault--;
            }
        }
    }
    return ans;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<swapCount(s)<<endl<<swapCount1(s)<<endl;
	}
	return 0;
}
