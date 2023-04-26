#include<bits/stdc++.h>
using namespace std;

// Method: Using backtracking find all paths
// when either bottom or right is reached only one
// choice of move is left so that is taken

vector<vector<int>> paths;

vector<int> mx = {0,1};
vector<int> my = {1,0};

void printAllPaths(vector<vector<int>> &mat, int x, int y, vector<int> path){
	int R = mat.size(), C = mat[0].size();

	// if reached destination
	if(x==R-1 and y==C-1){
		paths.push_back(path);
		return;
	}

	// if reached bottom then only move right
	if(x==R-1){
		int nx = x + mx[0];
		int ny = y + my[0];
		path.push_back(mat[nx][ny]);
		printAllPaths(mat,nx,ny,path);
		return;
	}

	// if reached right then only move right
	if(y==C-1){
		int nx = x + mx[1];
		int ny = y + my[1];
		path.push_back(mat[nx][ny]);
		printAllPaths(mat,nx,ny,path);
		return;
	}

	// if reached neither the bottom or the right
	for(int i=0;i<2;i++){
		int nx = x + mx[i];
		int ny = y + my[i];
		path.push_back(mat[nx][ny]);
		printAllPaths(mat,nx,ny,path);
		path.pop_back();
	}
	return;
}

int main(){
	vector<vector<int>> mat = {
		{1, 2, 3},
		{4, 5, 6}
	};

	// vector to store the current path
	// adding the source in the path
	vector<int> path(1,1);
	printAllPaths(mat,0,0,path);

	for(auto path:paths){
		for(auto e:path) cout<<e<<" ";
		cout<<endl;
	}

	mat = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
        {10,11,12,13,14,15,16,17,18},
		{19,20,21,22,23,24,25,26,27},
		{28,29,30,31,32,33,34,35,36}
    }; 
	path.assign(1,1);
	paths.clear();
	printAllPaths(mat,0,0,path);

	for(auto path:paths){
		for(auto e:path) cout<<e<<" ";
		cout<<endl;
	}

    return 0;
}
