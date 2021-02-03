    int hash_str[256] = {0};

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// return the smallest window in S with all the characters of P
// if no such window exists, return "-1" 
string smallestWindow (string S, string P){
    // Your code here
    int strLen = S.length();
    int patLen = P.length();
    if(patLen>strLen) return "-1";
    int hash_pat[256] = {0};
    int hash_str[256] = {0};
    for(int i=0;i<patLen;i++) hash_pat[P[i]]++;
    //count keeps track of number of characters matched
    // in string and pattern. Start keeps track of the 
    // starting index of the window. 
    int count=0,start=0,minLen=INT_MAX,start_index=-1;
    for(int i=0;i<strLen;i++){
        hash_str[S[i]]++;
        // if a character is repeated in a pattern then its
        // value will be more than 1 thus <= is used.
        if(hash_str[S[i]]<=hash_pat[S[i]]) count++;
        // When count becomes same as pattern length this means
        // that all the characters have been included in the window.
        if(count==patLen){
            // Now we try shortening the window length from the beginning
            // so as to get the shortest window but also keep all the characters
            // of the pattern in the string.
            while(hash_str[S[start]]>hash_pat[S[start]] or hash_pat[S[start]]==0){
                if(hash_str[S[start]]>hash_pat[S[start]]) hash_str[S[start]]--;
                start++;
            }
            int winLen = i-start+1;
            // If the new window length is smaller than the previous
            // we update the window lenght and its corresponding starting
            // index.
            if(winLen<minLen){
                minLen = winLen;
                start_index = start;
            }
        }
    }
    if(start_index==-1) return "-1";
    return S.substr(start_index,minLen);
}

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        
        cout<<smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
