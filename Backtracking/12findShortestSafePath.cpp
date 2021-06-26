#include<bits/stdc++.h>
using namespace std;


// Method: Using a loop start from all the safe cells of column 1
// and try to reach the last column (any cell in it) get the steps
// taken if minimum then store, else if not last column then mark
// the cell as visited and try the 4 possible moves from the current
// cell and move forward if no path found then we backtrack and mark
// this cell as not visited



// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
vector<int> rs = { -1, 0, 0, 1 };
vector<int> cs = { 0, -1, 1, 0 };

// function to check if step is safe
bool isSafe(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y){
    int R = matrix.size(), C = matrix[0].size();
	return (x>=0 and x<R and y>=0 and y<C and matrix[x][y]!=0 and !visited[x][y]);
}

// function to check if cell is in range of matrix
bool isValid(int x, int y, int R, int C){
	return (x>=0 and x<R and y>=0 and y<C);
}

// function to mark the adjacent of landmines with 0
void markUnsafe(vector<vector<int>> &matrix){
	int R = matrix.size();
	int C = matrix[0].size();

	// marking the cells containing landmines and 
	// there adjacents with -1 (first the cells are
	// marked then changed to 0, as if in the same
	// step we mark them as 0 then down the loop these
	// adjacent cells also get considered as landmines
	// and there adjacent are too marked as unsafe
	// finally leading to the whole matrix being marked
	// unsafe
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			if(matrix[i][j]==0){
				matrix[i][j] = -1;
				for(int k=0;k<4;k++){
					int nx = i+rs[k], ny = j+cs[k];
					if(isValid(nx,ny,R,C)) matrix[nx][ny] = -1;
				}
			}

	// marking the cells marked as -1 to 0
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			if(matrix[i][j]==-1) matrix[i][j] = 0;
}

// store minimum steps recorded so far
int minSteps = INT_MAX;

// final matrix to store the path marked by '9'
vector<vector<int>> fm;

void findShortestPathUtil(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y,
                          int steps){
    
    int R = matrix.size();
	int C = matrix[0].size();
    
    // if the last column is reached
    if(y==C-1){
        // if the current step is the minimum
        if(minSteps>steps+1){
            matrix[x][y] = 9;
            minSteps = steps+1;
            // the output matrix is updated
            fm = matrix;
            matrix[x][y] = 1;
        }
        return;
    }
    
    // if current path's steps are more than the minSteps
    // then this path is useless to traverse further
    if(steps>minSteps) return;
    
    // mark current cell as visited and also mark it as a
    // cell in the path
    visited[x][y] = true;
    matrix[x][y] = 9;
    
    // try to take the possible 4 steps and find a suitable path
    for(int k=0;k<4;k++){
        int nx = x+rs[k], ny = y+cs[k];
        if(isSafe(matrix,visited,nx,ny))
            findShortestPathUtil(matrix,visited,nx,ny,steps+1);
    }
    // if reached here means none of the 4 steps from the current
    // cell gives a safe path thus backtrack
    // mark this cell as unvisited to be used by some other path
    // also unmark the cell as path component
    visited[x][y] = false;
    matrix[x][y] = 1;
    
    return;
}

void findShortestPath(vector<vector<int>> &matrix){

	int R = matrix.size();
	int C = matrix[0].size();

	// keep track of visited cells
	vector<vector<bool>> visited;
    
    // keeping the exact copy to find the fm atlast
    // with the path in it
    vector<vector<int>> mcu = matrix;
    
	// mark the cells adjacent to landmines as unsafe
	// i.e. mark them as 0 (same as the landmines containing
	// cells)
	markUnsafe(matrix);
    
    // keeping the safe matrix copy so as to reinitiate
    // it to this for every cell in the first column
    // (starting point) 
    vector<vector<int>> mc = matrix;
    
	// traversing from all possible cells of 1st column
	// trying to reach the last column
	for(int i=0;i<R;i++)
		// if cell is safe to start from
		if(matrix[i][0]==1){
            // mark all cells as unvisited
            visited.assign(R,vector<bool>(C,false));
            
            // reinitiating the unsafe matrix because the old
            // one will contain a path in it that might not be
            // the shortest
            matrix = mc;
            
            // find shortest route from (i, 0) to any
            // cell of last column (x, C - 1) where
            // 0 <= x < R
            findShortestPathUtil(matrix,visited,i,0,0);
		}
    
    // getting the final matrix with the path in it
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(mcu[i][j]!=0 and fm[i][j]==0) fm[i][j] = 1;
        }
    }
    
    // if destination can be reached
    if (minSteps!=INT_MAX){
        cout<<"Length of shortest safe route is "<<minSteps<<endl;
        cout<<"The path in the matrix marked by '9'"<<endl;
        for(auto e:fm){
            for(auto f:e) cout<<f<<" ";
            cout<<endl;
        }
    }
    // if the destination is not reachable
    else cout<<"Destination not reachable from given source";
}

int main(){
	vector<vector<int>> matrix = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };

	findShortestPath(matrix);
	return 0;
}
