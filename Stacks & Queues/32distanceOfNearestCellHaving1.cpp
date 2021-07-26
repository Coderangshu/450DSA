	            

	            

	            

	            

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    
	    vector<vector<bool>> visited(n,vector<bool>(m,false));
	    vector<vector<int>> result(n,vector<int>(m,0));
	    
	    queue<pair<int,int>> q;
	    // taking all 1s as starting point and traversing to all
	    // 0s and storing the distance for each of them in that cell
	    
	    // BFS takes the smallest path thus for each node we get the
	    // nearest distance inside them
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            // if 1 in grid then a viable starting point
	            // push starting point to queue and mark visited
	            // and put 0 in result
	            if(grid[i][j]==1){
	                visited[i][j] = true;
	                result[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    int mx[] = { 0,0,-1,1};
	    int my[] = {-1,1, 0,0};
	    
	    int distance = 1;
	    while(!q.empty()){
	        int k = q.size();
	        for(int i=0;i<k;i++){
	            int x = q.front().first, y = q.front().second;
	            q.pop();
	            for(int j=0;j<4;j++){
	                int nx = x+mx[j], ny = y+my[j];
	                if(nx<0 or ny<0 or nx>=n or ny>=m or visited[nx][ny]) continue;
	                result[nx][ny] = distance;
	                visited[nx][ny] = true;
	                q.push({nx,ny});
	            }
	        }
	        if(!q.empty()) distance++;
	    }
	    return result;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
