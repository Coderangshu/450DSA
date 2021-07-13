// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int dp[n1+1][n2+2][n3+3];
    for(int i=0;i<n1+1;i++){
        for(int j=0;j<n2+1;j++){
            for(int k=0;k<n3+1;k++){
                if(i==0 or j==0 or k==0) dp[i][j][k] = 0;
                else if(A[i-1]==B[j-1] and B[j-1]==C[k-1]) dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                else dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
            }
        }
    }
    return dp[n1][n2][n3];
}
