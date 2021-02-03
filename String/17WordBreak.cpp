// Using recursion
// Reference: https://www.youtube.com/watch?v=1U4jQusbeJc
// Time complexity: O(2^n)
// Space complexity: O(n)
//// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) {
    //code here
    if(A.length()==0) return 1;
    for(auto e:B){
        if(A.substr(0,e.length())==e and wordBreak(A.substr(e.length(),A.length()-1),B)) return 1;
    }
    return 0;
}
