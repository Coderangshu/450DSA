// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
public:
    
    
    
    // Method 1: Using procedure analogous to concept of LCS
    // first finding the increasing unique array of given elements
    // then finding the LCS of this and the given array
    // Time = O(N^2) Space = O(N^2) 
    
    int lcs(int a[], int na,vector<int> b){
	    int nb = b.size();
	    
	    int dp[na+1][nb+1];
	    for(int i=0;i<na+1;i++){
	        for(int j=0;j<nb+1;j++){
	            if(i==0 or j==0) dp[i][j] = 0;
	            else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
	            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    return dp[na][nb];
	}
	
	int longestSubsequence(int n, int a[]) 
	{
	    // arranging the a and only keeping the unique numbers
	    set<int>s;
	    for(int i=0;i<n;i++) s.insert(a[i]);
	    vector<int>sortUniqVec = vector<int>(s.begin(),s.end());
	    
	    // finding longest common sum of sortUniqVec and a
	    int ans = lcs(a,n,sortUniqVec);
	    return ans; 
	}  
    
    
    
    
    
    // Method 2: Using binary search to get index of the element to be put in 
    // LIS and putting smaller ones in beginning and the larger ones in the end
    // thus getting the length of the LIS
    // Time = O(N^log(N)) Space = O(N) 
    
    
    int binarySearcher(vector<int> k, int l, int r, int val){
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (k[m] >= val)
                r = m;
            else
                l = m;
        }
        return r;
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       if(n==0) return 0;
        // stores the ordered subsequence
        vector<int> k(n,0);
        
        // considering the first element of a as the smallest
        k[0] = a[0];
        
        // length points to the next empty space in k
        int length = 1;
        
        for(int i=1;i<n;i++){
            // if new smaller element found replace with new smallest
            if(a[i]<k[0]) k[0] = a[i];
            
            // if greatest element is found
            else if(a[i]>k[length-1]) k[length++] = a[i];
            
            // else if in between we search location and replace
            else k[binarySearcher(k,-1,length-1,a[i])] = a[i];
        }
        
        // NOTE: k doesn't contain the actual increasing subsequence
        // see this for explanation of above method: 
        // http://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
        return length;
    }
    
    
    
    
    
    
    
    
    
    
    
    // Method 3: Another approach read the comments in between the code lines
    // Time = O(N^2) Space = O(N) 
    
    int longestSubsequence(int n, int a[])
    {
        // your code here
        // Store the LIS at each index of given a
        // initially all are longest on their own thus storing
        // 1 as each of their length
        vector<int> LIS(n,1);
       
        // notice both the loop's range
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++){
                // first check if jth element is smaller than
                // ith element if so then check if LIS at i is
                // less than 1+ LIS at j (1 is added because if 
                // we add the ith to the LIS of j than we are 
                // anticipating its length to increased by 1, if
                // its element is already 1 more than LIS[j] means
                // the i is already a part of an LIS that has same
                // length as that would be of the i being added to
                // j thus no brainer in it) then we include ith element
                // in the LIS of which j is a part of indicating that
                // i isn't part of any LIS or is part of a smaller
                // LIS
                if(a[i]>a[j] and LIS[j]+1>LIS[i])
                    LIS[i] = LIS[j]+1;
            }
        // return max length in LIS
        return *max_element(LIS.begin(),LIS.end());
    }
    
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
