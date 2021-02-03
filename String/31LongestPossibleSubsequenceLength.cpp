// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2){
    // your code here
    // We take an extra row and column to set
    // the strings which have non of the letters
    // from either of the strings, and their resultant
    // common subsequence length would be 0(As done 
    // letter in the loop to fill the table).
    int dp[x+1][y+1];
    for(int i=0;i<x+1;i++){
        for(int j=0;j<y+1;j++){
            if(i==0 or j==0) dp[i][j] = 0;
            // If the current characters of both the string are same
            // then we check the  longest common subsequence 
            // formed by the previous characters of both the strings,
            // then add 1 to it and store it.
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            // Else we check two conditions, removing the current element
            // from the first string and then removing it from the second
            // string, in both cases whichever has the highest length of
            // common subsequence that is what we save here, this means
            // that the one condition which has the more length of common
            // subsequence we keep that, i.e. include that letter in the
            // current longest possible subsequence, excluding the other
            // letter.
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    // Print dp array:
    
    // for(int i=0;i<x+1;i++){
    //     for(int j=0;j<y+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // The last cell contains the longest possible subsequence length
    return dp[x][y];
}

