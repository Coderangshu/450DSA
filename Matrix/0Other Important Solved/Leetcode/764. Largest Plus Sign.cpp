class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> mat(n,vector<int>(n,INT_MAX));
        for(auto e:mines) mat[e[0]][e[1]] = 0;
        
        for(int i=0;i<n;i++){
            int l = 0, r = 0, u = 0, d = 0;
            for(int j=0,k=n-1;j<n;j++,k--){
                // ith row left to right
                mat[i][j] = min(mat[i][j],l=(mat[i][j]==0)?0:l+1);
                // ith row right to left
                mat[i][k] = min(mat[i][k],r=(mat[i][k]==0)?0:r+1);
                // ith col top to bottom
                mat[j][i] = min(mat[j][i],u=(mat[j][i]==0)?0:u+1);
                // ith col bottom to top
                mat[k][i] = min(mat[k][i],d=(mat[k][i]==0)?0:d+1);
            }
        }
        
        // for(auto e:mat){
        //     for(auto f:e) cout<<f<<" ";
        //     cout<<endl;
        // }
        
        int ans = 0;
        for(auto e:mat) for(auto f:e) ans = max(ans,f);
        return ans;
    }
};