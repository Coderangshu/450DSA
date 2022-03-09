// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    
    
    
    
    // Method I: Using Dynamic Programming (T(n) is less than O(n^2))
    //           Based on observations of knights movement in chessboard
    
    // memo[a][b], here a, b is the difference of x & tx and y & ty respectively.
    // (x,y) is knight's position and (tx,ty) is target position
    int memo[1001][1001];
      
    int getsteps(int x, int y, int tx, int ty, int n){
        int dx = abs(x-tx), dy = abs(y-ty);
        
        // if knight is on the target position return memo[0][0].
        if(dx==0 and dy==0) return memo[0][0]=0;
        
        
        // (Exception) these are the four corner points for which the minimum steps is 4.
        // when target and knight are corner adjacent and is present in either of the 4 corners
        // of the chessboard then always 4 steps are required to reach target
        if ((x==1 and y==1 and tx==2 and ty==2) or (x==2 and y==2 and tx==1 and ty==1))
            return 4;
        else if ((x==1 and y==n and tx==2 and ty==n-1) or (x==2 and y==n-1 and tx==1 and ty==n))
            return 4;
        else if ((x==n and y==1 and tx==n-1 and ty==2) or (x==n-1 and y==2 and tx==n and ty==1))
            return 4;
        else if ((x==n and y==n and tx==n-1 and ty==n-1) or (x==n-1 and y==n-1 and tx==n and ty==n))
            return 4;
            
        
        // When points are one above other in adjacent row
        else if(dx==1 and dy==0) return memo[1][0] = 3;
        else if(dx==0 and dy==1) return memo[0][1] = 3;
        // When points in adjacent corner of each other but not in corner of chessboard
        else if(dx==1 and dy==1) return memo[1][1] = 2;
        // When points are vertically in straight line but with one row gap
        else if(dx==2 and dy==0) return memo[2][0] = 2;
        else if(dx==0 and dy==2) return memo[0][2] = 2;
        // When points are in the path followed by knight 2 and a half then only one step required
        else if(dx==2 and dy==1) return memo[2][1] = 1;
        else if(dx==1 and dy==2) return memo[1][2] = 1;
        
        
        else {
            // if already calculated then return
            // that value. Taking absolute difference.
            if (memo[abs(x - tx)][abs(y - ty)] != -1)
                return memo[abs(x - tx)][abs(y - ty)];
                  
            else {
                // there will be two distinct positions from the knight towards a target.
                
                // (I) if the target is in same row or column as of knight than there can be four
                //     positions towards the target but in that two would be the same and the other
                //     two would be the same w.r.t steps away from target. So we take only one of
                //     both type
                int x1, y1, x2, y2;
                  
                // (II) (x1, y1) and (x2, y2) are in the two different possible positions which will be
                //      nearer to the target, these can be different according to situation. From position
                //      of knight, the chess board can be divided into four blocks 
                //      i.e.. N-E, E-S, S-W, W-N . Accordingly going towards the target via the shortest
                //      path(step)
                if (x <= tx) {
                    if (y <= ty) {
                        x1 = x + 2;
                        y1 = y + 1;
                        x2 = x + 1;
                        y2 = y + 2;
                    } else {
                        x1 = x + 2;
                        y1 = y - 1;
                        x2 = x + 1;
                        y2 = y - 2;
                    }
                } else {
                    if (y <= ty) {
                        x1 = x - 2;
                        y1 = y + 1;
                        x2 = x - 1;
                        y2 = y + 2;
                    } else {
                        x1 = x - 2;
                        y1 = y - 1;
                        x2 = x - 1;
                        y2 = y - 2;
                    }
                }
                  
                // ans will be, 1 + minimum of steps required from (x1, y1) or (x2, y2).
                memo[abs(x-tx)][abs(y-ty)] = min(getsteps(x1,y1,tx,ty,n),getsteps(x2,y2,tx,ty,n))+1;
                                 
                // exchanging the coordinates x with y of both knight and target will result in same ans.
                memo[abs(y-ty)][abs(x-tx)] = memo[abs(x-tx)][abs(y-ty)];
                return memo[abs(x-tx)][abs(y-ty)];
            }
        }
    }
    
    
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
        memset(memo,-1,sizeof(memo));
        int x = KnightPos[0], y = KnightPos[1];
        int tx = TargetPos[0], ty = TargetPos[1];
        return getsteps(x, y, tx, ty,N);
    }
    
    
    
    
    
    
    // Method II: Using BFS
    
    
    
    // Struct of a cell to store index of knight and steps from initial position
    struct cell{
        int x,y,step;
        cell(){}
        cell(int ex, int yi, int stps){
            x = ex;
            y = yi;
            step = stps;
        }
    };
    
    // To check if knight is in chess board and not visited previously
    bool isSafe(int x, int y, int N, vector<vector<bool>> visited){
        if(x>=0 and x<N and y>=0 and y<N and !visited[x][y]) return true;
        return false;
    }
    
	int minStepToReachTarget1(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    // x and y direction, where a knight can move
        int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        
        // Starting standard BFS procedure
        
        // queue for storing states of knight in board
        queue<cell> q;
        
        // Initiate a visited array to keep track of visited 
        // nodes of knight with all nodes as false
        vector<vector<bool>> visited(N,vector<bool>(N,false));
        
        // Set initial cell as visited
        visited[KnightPos[0]-1][KnightPos[1]-1] = true;
        // push starting position of knight with 0 steps
        q.push(cell(KnightPos[0]-1, KnightPos[1]-1, 0));
        
        while(!q.empty()){
            cell nc = q.front();
            q.pop();
            
            // if current cell is equal to target cell,
            // return its steps, we are returning the first
            // cell's distance steps when position is matching
            // with target at BFS will get to the target node
            // with the shortest possible path
            if (nc.x == TargetPos[0]-1 and nc.y == TargetPos[1]-1)
                return nc.step;
                
            for(int i=0;i<8;i++){
                int ax = nc.x + dx[i];
                int ay = nc.y + dy[i];
                // If next state is not yet visited and inside board,
                // push that state into queue
                if (isSafe(ax, ay, N,visited)) {
                    visited[ax][ay] = true;
                    q.push(cell(ax, ay, nc.step + 1));
                }
            }
        }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
