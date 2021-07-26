// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        // BFS traversal
        // stores index of rotten oranges
        queue<pair<int,int>> rotten;
        
        // first count total oranges in grid and push the rotten
        // into the queue to be processed
        int totOranges = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // if cell not empty
                if(grid[i][j]!=0){
                    totOranges++;
                    // if rotten push to queue
                    if(grid[i][j]==2) rotten.push({i,j});
                }
            }
        }
        
        int mx[] = { 0,0,-1,1};
        int my[] = {-1,1, 0,0};
        
        // count of total oranges rotted or will rot
        int cntRot = 0, days = 0;
        while(!rotten.empty()){
            // getting number of oranges rotten each day
            int k = rotten.size();
            cntRot += k;
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                // traversing all 4 directions from current node
                for(int i=0;i<4;i++){
                    int nx = x+mx[i], ny = y+my[i];
                    // if index out of bound or orange not present
                    // or rotten from before then ignore
                    if(nx<0 or ny<0 or nx>=n or ny>=m or grid[nx][ny]!=1)
                        continue;
                    // else rot the fresh orange and push to queue
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                }
            }
            // at end of day we check if rotten isn't empty
            // means another day is required to rot oranges
            // increasing day to rot all fresh oranges
            if(!rotten.empty()) days++;
        }
        // now check if all oranges in grid have rotted or not
        // then return number of days else not possible return -1
        return (totOranges==cntRot)?days:-1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
