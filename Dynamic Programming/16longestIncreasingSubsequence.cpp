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
    
    
    int binarySearcher(vector<int> k, int r, int val){
        int l = 0;
        while (l<r) {
            int m = (l+r)>>1;
            if (k[m] >= val)
                r = m;
            else
                l = m+1;
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
            else k[binarySearcher(k,length-1,a[i])] = a[i];
        }
        
        // NOTE: k doesn't contain the actual increasing subsequence
        // see this for explanation of above method: 
        // http://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
        return length;
    }
    
    // Same approach as above, we just retrieve the LIS using extra space by maintaining a path array which
    // keeps track of the LIS from the end to the beginning
    // Time Complexity  : O(nlogn)
    // Space Complexity : O(3*n) ~ O(n)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // solving for [9,10,2,5,3,7,101,18]
        
        // lis : []
        // lisi : []
        // path : [-1,-1,-1,-1,-1,-1,-1,-1]
        // lis keeps track of the length of the LIS and also
        // the elements (they may not be the LIS, but the last
        // element of lis is sure to be the last element of the LIS),
        // lisi keeps track of the lis's element's indices.
        // path keeps track of the indices from the last index of the LIS
        // with the help of lisi to get the path to the longest increasing
        // subsequence, the longest path is found until -1 is obtained in
        // the path.
        vector<int> lis,lisi, path(n,-1);
        
        for(int i=0;i<n;i++){
            if(lis.empty() or lis.back()<nums[i]){
                path[i] = (lis.empty())?-1:lisi.back();
                lis.push_back(nums[i]);
                lisi.push_back(i);
            }
            else{
                int ind = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                path[i] = (ind!=0)?lisi[ind-1]:-1;
                lis[ind] = nums[i];
                lisi[ind] = i;
            }
        }
        // Dry Run for above for loop
        // i=0 -> lis  : [9]
        //        lisi : [0]
        //        path : [-1,-1,-1,-1,-1,-1,-1,-1]
        // i=1 -> lis  : [9,10]
        //        lisi : [0,1]
        //        path : [-1,0,-1,-1,-1,-1,-1,-1]
        // i=2 -> lis  : [2,10]
        //        lisi : [2,1]
        //        path : [-1,0,-1,-1,-1,-1,-1,-1]
        // i=3 -> lis  : [2,5]
        //        lisi : [2,3]
        //        path : [-1,0,-1,2,-1,-1,-1,-1]
        // i=4 -> lis  : [2,3]
        //        lisi : [2,4]
        //        path : [-1,0,-1,2,2,-1,-1,-1]
        // i=5 -> lis  : [2,3,7]
        //        lisi : [2,4,5]
        //        path : [-1,0,-1,2,2,4,-1,-1]
        // i=6 -> lis  : [2,3,7,101]
        //        lisi : [2,4,5,6]
        //        path : [-1,0,-1,2,2,4,5,-1]
        // i=7 -> lis  : [2,3,7,18]
        //        lisi : [2,4,5,7]
        //        path : [-1,0,-1,2,2,4,5,5]
        
        // ans : [_,_,_,_]
        int lisn = lis.size();
        vector<int> ans(lisn);
        int i = lisn-1;
        
        int t = lisi.back();
        while(t!=-1){
            ans[i--] = nums[t];
            t = path[t];
        }
        // Dry Run for above while loop
        // t=7 -> ans : [_,_,_,18]
        // t=5 -> ans : [_,_,7,18]
        // t=4 -> ans : [_,3,7,18]
        // t=2 -> ans : [2,3,7,18]
        // t=-1 -> loop ends

        for(auto e:ans) cout<<e<<" ";
        cout<<endl;
        return lisn;
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
