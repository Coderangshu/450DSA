// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of islands.
    
        
        
        
        
    // Method I: Using BFS/DFS to find no. of components
        
        
        
    bool isSafe1(int i, int j, vector<vector<char>> grid){
        int rows = grid.size(), cols = grid[0].size();
        return (i>=0) and (i<rows) and (j>=0) and (j<cols) and (grid[i][j]=='1');
    }
    
    // Either DFS
    void DFS(int i, int j, vector<vector<char>> &grid){
        // These arrays are used to get row and column numbers of 8
        // neighbours of a given cell
        int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        
        // Land node visited thus make it water
        grid[i][j] = '0';
        // Visit its adjacent nodes
        for(int k=0;k<8;k++){
            int row = i+rowNbr[k], col = j+colNbr[k];
            if(isSafe1(row,col,grid))
                DFS(row,col,grid);
        }
    }
    
    // Or BFS
    void BFS(int i, int j, vector<vector<char>> &grid){
        int rows = grid.size(), cols = grid[0].size();
        // These arrays are used to get row and column numbers of 8
        // neighbours of a given cell
        int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        
        // As this land node is visited we make it a water, so that
        // in furthur iterations this node isn't taken into consideration
        grid[i][j] = '0';
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            i = p.first, j = p.second;
            for(int k=0;k<8;k++){
                int row = i+rowNbr[k], col = j+colNbr[k];
                if(isSafe1(row,col,grid)){
                    // Land node visited thus make it water
                    grid[row][col] = '0';
                    q.push(make_pair(row,col));
                }
            }
        }
    }
    
    
    // Similar to 10numberOfOpsToMakeNetworkConnected use either BFS or DFS
    // to find the number of components in the graph, here different components
    // define different islands
    int numIslands1(vector<vector<char>>& grid) 
    {
        // Code here
        int rows = grid.size(), cols = grid[0].size();
//         vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int islands = 0;
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    // '1' means a new land node has been found
                    islands++;
                    // Using BFS/DFS water conquers all the lands connected
                    // to this node (i.e. the whole island) 
                    DFS(i,j,grid);
                }
            }
        }
        return islands;
    }
    
    
    
    
    
    
    // Method II: Using Find Union to find the common ultimate parent of all nodes
    // thus the total number of ultimate nodes gives us the total number of islands
    
    bool isSafe(int i, int j, vector<vector<char>> grid){
        int rows = grid.size(), cols = grid[0].size();
        return (i>=0) and (i<rows) and (j>=0) and (j<cols) and (grid[i][j]=='1');
    }
    
    
    vector<int> parent;
    
    int findParent(int node){
        int p = parent[node];
        if(p!=node){
            return parent[node] = findParent(p);
        }
        else return p;
    }
    
    int numIslands(vector<vector<char>>& grid){
        
        // These arrays are used to get row and column numbers of 8
        // neighbours of a given cell
        int r[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int c[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        
        int rows = grid.size(), cols = grid[0].size();
        // set all nodes as standalone(make themselves their parent)
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                parent.push_back(i*cols+j);
            
        int noOfOnes = 0;
            
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                // When grid[i][j] is 0 ignore
                if(grid[i][j]=='0') continue;
                else{
                    noOfOnes++;
                    // finding parent of current node
                    int ultimateParent = findParent(i*cols+j);
                    // traversing through all adjacent nodes of
                    // current node
                    for(int k=0;k<8;k++){
                        int row = i+r[k], col = j+c[k];
                        if(isSafe(row,col,grid)){
                            int nodeParent = findParent(row*cols+col);
                            // if parent of current and neighbour nodes
                            // isn't same make higher parent as parent of
                            // lower parent this makes all nodes under
                            // lower parent under higher parent
                            // Here we can use this property as we are
                            // traversing from lower to higher node
                            
                            // This is naive union set finding
                            // this procedure takes linear time to find the disjoint
                            // sets, using rank decreases T(n) to logarithmic scale
                            // and using rank along with path compression reduces T(n)
                            // to constant
                            if(nodeParent>ultimateParent)
                                parent[nodeParent] = ultimateParent;
                        }
                    }
                }
            }
        }
        
        for(auto e:parent) cout<<e<<" ";
        cout<<endl;
        
        // total components contain all the islands and each of the
        // water nodes as individual component
        int components = 0;
        // when parent same as node values denotes this is the
        // head of a component thus incrementing components
        for(int i=0;i<parent.size();i++) if(parent[i]==i) components++;
        
        // noOfOnes contains total no. of land nodes in graph
        // total nodes - total lands gives total water nodes
        return components-(rows*cols-noOfOnes);
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends




// Input format:
// 2
// 5 5
// 1 1 0 0 0
// 0 1 0 0 1
// 1 0 0 1 1
// 0 0 0 0 0
// 1 0 1 0 1
// 7 10               
// 1 0 0 0 0 1 0 0 0 1
// 1 0 1 1 1 1 1 0 0 1
// 1 1 1 1 1 0 0 0 1 0
// 1 1 1 0 1 0 0 1 0 1
// 0 1 0 1 0 0 0 1 0 0
// 0 0 0 0 0 1 1 1 1 0
// 0 0 1 1 0 0 0 1 0 0


