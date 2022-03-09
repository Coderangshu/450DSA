                   // j then we break at point i

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    // prints the starting and ending indexes of
    // words in each line
    int printSolution (vector<int> p, int n){
        int k;
        if (p[n] == 1)
            k = 1;
        else
            k = printSolution (p, p[n]-1) + 1;
        cout<<"Line number "<<k<<": From word no. "<<p[n]<<" to "<<n<<endl;
        return k;
    }

    int calMinCost(vector<int> p, int n, vector<vector<int>> &ac){
        if(p[n]==1) return ac[p[n]-1][n-1];
        return ac[p[n]-1][n-1]+calMinCost(p,p[n]-1,ac);
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        
        // allCosts stores all the possible cost
        // for all the combinations(i.e. square of
        // the extra spaces spent in each line)
        vector<vector<int>> allCosts(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<=j){
                    // space taken by words in one line under current
                    // configuration (i.e. word i to word j)
                    int sumOfWords = accumulate(nums.begin()+i,nums.begin()+j+1,0);
                    // spaces required between each word
                    int sumOfReqSpace = j-i==0?0:j-i;
                    int totSpace = sumOfWords+sumOfReqSpace;
                    if(totSpace<=k) allCosts[i][j] = pow(k-totSpace,2);
                    else allCosts[i][j] = INT_MAX;
                }
            }
        }
        
        // stores the min cost upto ith index
        vector<int> mc(n+1,INT_MAX);
        // stores the starting index(1 indexed) upto the
        // current index in it
        // Example: partitions = {-1,1,1,2,4}
        // partitions[0] = -1 as 1 indexed is followed
        // thus garbage value stored inside partitions[0]
        // index 1 stores 1 meaning that upto this index
        // the numbers to be fitted in a line are from 1 to 1
        // i.e. partitions[i] to i
        // similar for i=2, 1 to 2 are to be fitted
        // for i=3, 2 to 3(observe:dp optimized the space here)
        // for i=4, 4 to 4
        // Thus line 1 : 1 to 1
        //      line 2 : 2 to 3
        //      line 3 : 4 to 4
        vector<int> partitions(n+1,-1);
        mc[0] = 0;
        for(int j=1;j<=n;j++){
            for(int i=1;i<=j;i++){
                // NOTE: herein allCosts follows 1 indexing
                // and mc 0 indexing
                
                // if allCosts from current i to j isn't MAX
                // and the sum of cost from 0 to upto the 
                // (i-1)th index and cost from i to j is less
                // than cost at j then we break at point i
                if(allCosts[i-1][j-1]!=INT_MAX and 
                        mc[i-1]+allCosts[i-1][j-1]<mc[j]){
                    mc[j] = mc[i-1]+allCosts[i-1][j-1];
                    partitions[j] = i;
                }
            }
        }
        
        // printSolution(partitions,n);
        
        return calMinCost(partitions,partitions[n]-1,allCosts);
    } 
};


// trying out not yet working
class Solution1 {
private:
    int ans = INT_MAX;
    void recursion(vector<int>nums, int k, int i, int rl, int s, int ls){
        int n = nums.size();
        if(i==n-1){
            s += pow(ls,2);
            ans = min(ans,s);
        }
        if(nums[i]<rl){
            if(rl==k){
                if(rl-nums[i]>0) recursion(nums,k,i+1,rl-nums[i],s,ls);
                else recursion(nums,k,i+1,k,s+pow(ls,2),0);
            }
            else{
                if(rl-nums[i]-1>0) recursion(nums,k,i+1,rl-nums[i]-1,s,ls+1);
                else recursion(nums,k,i+1,k,s+pow(ls,2),0);
            }
        }
        recursion(nums,k,i+1,k,s+pow(ls+rl,2),0);
        return;
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        recursion(nums,k,0,k,0,0);
        return ans;
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution1 obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
