// Dynamic Programming
// For reference: https://youtu.be/AuYujVj646Q
// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    // Code here
		    // total number of INSERT,REPLACE,REMOVE
		    // required to make s same as t.
		    int sLen = s.length();
		    int tLen = t.length();
		    // Row index represent number of elements from
		    // beginning considered of string t, and row 
		    // index represents the same for string s.
		    int d[tLen+1][sLen+1];
		    // If s is 0 this means to make s to t we need
		    // to INSERT all the elements of t to s and so on.
		    // If t is 0 means we have to REMOVE all elements
		    // from s to make it same as t. Thus the first if
		    // condition.
		    for(int i=0;i<=tLen;i++){
		        for(int j=0;j<=sLen;j++){
		            if(i==0 or j==0){
		                if(i==0) d[i][j] = j;
		                else d[i][j] = i;
		            }
			    // If the last element of each string are equal i.e. the last
			    // characters in both the string in consideration. Then we can
			    // move forward with 0 actions taken, thus the number of actions
			    // taken so far remains same.
		            else if(s[j-1]==t[i-1]) d[i][j] = d[i-1][j-1];
			    // If the characters in consideration are not equal then we have
			    // 3 possibilities-INSERT,REMOVE,REPLACE.
			    // Note: For insertion we always insert it to the right of the 
			    // current character.
			    //
			    // If we are to REMOVE the element at the last position (current
			    // position) of s, the index of the s's current element is
			    // decremented but index of t's current element remains same- this
			    // implies that number of operations done till now to match the second
			    // last index character of s(as the last character is removed now) and
			    // the last index character of t, that number of operations and an extra
			    // number of edit done to remove the last character is placed at d[i][j]
			    // thus incrementing the prvious result by one.
			    //
			    // If we are to INSERT the element at the last position (current
                            // position) of s,the index of the s's current element remains same but
			    // index of t's current element is decremented as now the last character
			    // of t matches the last character of s, and now j points to the second 
			    // last character of s and we decrement i to point to the second last 
			    // element of t, and we add one to denote the INSERT action done just now.
			    //
			    //If we are to REPLACE the element at the last position (current
                            // position) of s, we simply decrement both s's index and t's index
			    // as now both the last characters of s and t are equal, and add one to number
			    // of edits done so far.
			    // We store the minimum of the all 3 actions as this would give us the minimum 
			    // number of edits done so far.
		            else d[i][j] = min(d[i-1][j],min(d[i][j-1],d[i-1][j-1]))+1;
		        }
		    }
		    // The [sLen,tLen] term gives us the total number of minimum edits done so far to get s
		    // same as t.
		    return d[tLen][sLen];
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends
