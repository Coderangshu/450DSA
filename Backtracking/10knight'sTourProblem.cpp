#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(8^(n^2)) where n is side length of board

// More efficient but heuristics search method is WarnsDordd's algorithm
// See : https://www.geeksforgeeks.org/warnsdorffs-algorithm-knights-tour-problem/


bool isSafe(int x, int y, vector<vector<int>> &ans){
	int n = ans.size();
	return (x>=0 and x<n and y>=0 and y<n and ans[x][y]==-1);
}

bool getKnightTourUtil(int x, int y, int steps, vector<vector<int>> &ans){

	int n = ans.size();
	// if all cells have been traversed then return
	if(steps+1==n*n) return true;

	// The next possible moves of a knight
	vector<int> xNxt = {2,1,-1,-2,-2,-1, 1, 2};
	vector<int> yNxt = {1,2, 2, 1,-1,-2,-2,-1};

	// Try all 8 possible moves from current location
	// similar to BFS traversal
	for(int i=0;i<8;i++){
		// getting next possible position after taking a move
		int nxtX = x+xNxt[i];
		int nxtY = y+yNxt[i];
		// if safe position then add to ans
		if(isSafe(nxtX,nxtY,ans)){
			ans[nxtX][nxtY] = steps+1;
			// send for next move
			// if true then this is correct configuration
			// else backtrack by resetting the value at
			// (nxtX,nxtY) as -1
			if(getKnightTourUtil(nxtX,nxtY,steps+1,ans)) return true;
			else ans[nxtX][nxtY] = -1;
		}
	}
	// if loop exited means no suitable move found thus no possible
	// arrangement for following configuration
	return false;
}	

// wrapper function to get route of knight using
// backtracking
// NOTE: this isnt the only path for the knight
// this is one of the possible paths generated
void getKnightTour(vector<vector<int>> &ans){

	// In starting knight is present at (0,0) thus in ans matrix
	// we put 0 in (0,0) as 0 steps are required to reach there
	ans[0][0] = 0;

	getKnightTourUtil(0,0,0,ans);
}

int main(){
	int n = 8;
	vector<vector<int>> ans(n,vector<int>(n,-1));
	getKnightTour(ans);

	// Print ans
	for(auto row:ans){
		for(auto cell:row) cout<<cell<<"\t";
		cout<<endl;
	}

	return 0;
}
