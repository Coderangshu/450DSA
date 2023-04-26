// Question : https://www.interviewbit.com/problems/potions/

// Similar to Burst balloon problem
// need to start from the last situation
// last situation would be left with 2 elements only and cost returned would
// be their product.
// Simulating the procedure for array [2, 3, 4, 5]:
// for each partition considering left and right to be 2 individual elements
// and calculating the cost of merging these 2 elements

// cost2Merge([2]) + 2%100*(3+4+5)%100 + cost2Merge([3,4,5])
// cost2Merge([2,3]) + (2+3)%100*(4+5)%100 + cost2Merge([4,5])
// cost2Merge([2,3,4]) + (2+3+4)%100*5%100 + cost2Merge([5])

// final cost would be min of above 3 situations

Solution{
    private:
    int recursion(vector<int> &a, int l, int r){
        if(l>=r) return 0;
        int sa = 0, ans = INT_MAX, sb = accumulate(a.begin()+l,a.begin()+r+1,0);
        for(int i=l;i<r;i++){
            sa += a[i];
            sb -= a[i];
            ans = min(ans,recursion(a,l,i) + (sa%100)*(sb%100) + recursion(a,i+1,r));
        }
        return ans;
    }

    int tabulation(vector<int> &A){
        int n = A.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int l=n-1;l>=0;l--){
            for(int r=0;r<n;r++){
                if(l<r){
                    int sa = 0, ans = INT_MAX, sb = accumulate(A.begin()+l,A.begin()+r+1,0);
                    for(int i=l;i<r;i++){
                        sa += A[i];
                        sb -= A[i];
                        ans = min(ans,dp[l][i] + (sa%100)*(sb%100) + dp[i+1][r]);
                    }
                    dp[l][r] = ans;
                }
            }
        }
        return dp[0][n-1];
    }

    public:
    int minSmoke(vector<int> &A) {
        // return recursion(A,0,A.size()-1);
        return tabulation(A);
    }
};