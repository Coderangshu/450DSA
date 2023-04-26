#include<bits/stdc++.h>
using namespace std;



// Method: The idea is to use Backtracking. We start from the source cell of the matrix,
// move forward in all four allowed directions and recursively checks if they leads to 
// the solution or not. If destination is found, we update the value of longest path 
// else if none of the above solutions work we return false from our function.



bool isSafe(int R, int C, int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &matrix){
	return (x>=0 and x<R and y>=0 and y<C and !visited[x][y] and matrix[x][y]!=0);
}

// moves available(x,y) coordinates
vector<int> mx = {-1,0,1, 0};
vector<int> my = { 0,1,0,-1};

// variable to store the max steps
int maxSteps = INT_MIN;
// to store the longest path using 1s(used) and
// 0s (not used) 
vector<vector<bool>> ans;

bool findLongestPathUtil(vector<vector<int>> &matrix, pair<int,int> s, pair<int,int> d,
					 vector<vector<bool>> &visited, int steps){
	if(s==d){
		if(maxSteps<steps){
            maxSteps = steps;
            auto [sx,sy] = s;
            visited[sx][sy] = true;
            ans = visited;
            visited[sx][sy] = false;
        }
		return true;
	}

	int R = matrix.size();
	int C = matrix[0].size();
	auto [sx,sy] = s;
	auto [dx,dy] = d;
	
	visited[sx][sy] = true;

	bool a = false;
	for(int i=0;i<4;i++){
		int nx = sx+mx[i];
		int ny = sy+my[i];
		if(isSafe(R,C,nx,ny,visited,matrix))
			a = findLongestPathUtil(matrix,{nx,ny},d,visited,steps+1) or a;
	}
	visited[sx][sy] = false;
	return a;
}

void findLongestPath(vector<vector<int>> &matrix, pair<int,int> s, pair<int,int> d){
    // resetting maxSteps for next problem
    maxSteps = INT_MIN;
    
	int R = matrix.size();
	int C = matrix[0].size();

	auto [sx,sy] = s;
	auto [dx,dy] = d;

	vector<vector<bool>> visited(R,vector<bool>(C,false));

	if(findLongestPathUtil(matrix,s,d,visited,0)){
		cout<<"Longest path length is: "<<maxSteps<<endl;
        cout<<"The path is shown using 1s"<<endl;
        for(auto e:ans){
            for(auto v:e) cout<<v<<" ";
            cout<<endl;
        }
    }
	else cout<<"No Possible Path"<<endl;
}

int main(){
	vector<vector<int>> matrix =  {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
	pair<int,int> src = {0,0};
	pair<int,int> dest = {1,7};

	findLongestPath(matrix,src,dest);
    
    matrix =  {
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 0, 1, 0, 1 },
        { 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
    
    src = {0,0};
	dest = {1,7};

	findLongestPath(matrix,src,dest);
    
	return 0;
}
