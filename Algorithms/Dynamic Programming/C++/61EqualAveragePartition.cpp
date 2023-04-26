// Question : https://www.interviewbit.com/problems/equal-average-partition/

#include<bits/stdc++.h>

Solution{
    private:
        int isPossible(vector<int> &a, int i, int c, int s1, vector<int> &ans, vector<vector<vector<int>>> &dp){
        int n = a.size();
        if(c<0 or s1<0) return 0;
        if(c==0) return dp[i][c][s1] = (s1==0)?1:0;
        if(i==n) return 0;
        if(dp[i][c][s1]!=-1) return dp[i][c][s1];
        if(a[i]<=s1){
            ans.push_back(a[i]);
            if(isPossible(a,i+1,c-1,s1-a[i],ans,dp)) return dp[i][c][s1] = 1;
            ans.pop_back();
        }
        return dp[i][c][s1] = isPossible(a,i+1,c,s1,ans,dp);
    }

    public:
    vector<vector<int>> avgset(vector<int> &A) {
        int n = A.size(), s = accumulate(A.begin(),A.end(),0);
        sort(A.begin(),A.end());
        vector<int> a,b;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(s+1,-1)));
        // we need divide such that, s1/n1 == s2/n2
        // simplifying above equation (taking all in terms of s1 and n1):
        // s1/n1 = (s-s1)/(n-n1)    (s = total sum, n = total elements)
        // cross multiplying and simplifying
        // s1 = (s*n1)/n

        // thus we take all lengths of 1st array, i.e. n1 as 1 -> n-1
        // and check  for each length if we get integer value for (s*n1)/n (because s1 must be integer)
        // then proceed to find that length array, this would be our 1st array, rest will be in 2nd array
        
        for(int i=1;i<n;i++){
            if((i*s)%n==0){
                int s1 = (i*s)/n;
                if(isPossible(A,0,i,(i*s)/n,a,dp)){
                    int i = 0, j = 0;
                    while(i<n and j<n){
                        if(a[i]==A[j]) i++,j++;
                        else b.push_back(A[j++]);
                    }
                    return vector<vector<int>> {a,b};
                }
            }
        }
        return vector<vector<int>>{};
    }
}