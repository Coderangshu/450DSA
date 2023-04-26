// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<iostream>
#include<cstring>
using namespace std;
 
// Function return the total palindromic subsequence
int countPS(string str);
 
// Driver program
int main()
{
   int t;
	cin>>t;
   while(t--)
	{
	string str;
cin>>str;
cout<<countPS(str)<<endl;
} 
}// } Driver Code Ends


/*You are required to complete below method */

int countPS(string str)
{
   //Your code here
   int n = str.length();
   long long dp[n][n] = {0};
   // Table fills up only in the upper triangle.
   // See 8LargestPalindrome.cpp
   // In this dp we store the number of palindromes
   // possible with each strings present.
   // All single characters are palindromes.
   for(int i=0;i<n;i++) dp[i][i] = 1;
   // Checking for substrings with lengths 2 and more.
   // Below loop signifies the length of the substring not
   // index like the previous ones.
   for(int i=2;i<=n;i++){
       for(int j=0;j<n-i+1;j++){
           int k = j+i-1;
           // Checking all possible strings of length i
           // starting from j to k indexes.
           // If jth and kth index of str are same then they will
           // make a palindrome. We refer to the previous indexes
           // position and see the number of palindromes formed
           // uptill them, then add 1 to denote the new one formed.
           if(str[j]==str[k]) dp[j][k] = dp[j][k-1]+dp[j+1][k]+1;
           // Else we take the number of possible palidromes with
           // the last indexes subtract the common ones between them
           // (just like venn diagram union) and store it in the dp's
           // current index.
           else dp[j][k] = dp[j][k-1]+dp[j+1][k]-dp[j+1][k-1];
       }
   }
//   for(int i=0;i<n;i++){
//       for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
//       cout<<endl;
//   }
   return dp[0][n-1];
}
 
