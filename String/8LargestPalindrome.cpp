#include<bits/stdc++.h>
using namespace std;

void printSubStr(string str, int low, int high){
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

void palindrome(string s){
    int n = s.length();
    // In this dp table the row number denotes
    // starting index of a substring and column number
    // end.
    int dp[n][n];                                                                   // Space complexity=O(n^2).
    // Now we fill the two base cases.
    // filling the diagonal with one as all
    // single character are palindrome.
    for(int i=0;i<n;i++) dp[i][i] = 1;                                              // Time complexity=O(n).
    int maxLen = 1;
    int start;
    // double character if (both equal)? isPalindrome
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){                                                           // Time complexity=O(n).
            dp[i][i+1] = 1;
            start = i;
            maxLen = 2;
        }
        else dp[i][i+1] = 0;
    }
    
    // Checking for substring lengths greater than 2.
    for(int i=3;i<=n;i++){
        // taking into consideration all possible substring
        // of length i.
        for(int j=0;j<n-i+1;j++){
            int k = j+i-1;
            // Now index j to k are all the possible substring
            // of length i. To check palindrome we just need to
            // check the first and the last char and for the rest
            // middle string we lookup in the dp table by increasing
            // the j by one and decreasing k by one.
            if(dp[j+1][k-1] and s[j]==s[k]){
                dp[j][k]=1;
                // The maxlength of palindromic substring is also
                // updated from here.
                if(i>maxLen){
                    maxLen = i;
                    start = j;
                }
            }
            else dp[j][k]=0;
        }
    }
    printSubStr(s, start, start + maxLen-1);
}

int main()
 {
	//code
	int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        palindrome(s);
    }
	return 0;
}
