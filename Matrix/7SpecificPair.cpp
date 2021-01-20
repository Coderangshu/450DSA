#include <bits/stdc++.h>
using namespace std;

#define N 5

int findMaxDiff(int M[][N]){
	// Store max difference
	int maxDiff = INT_MIN;
	// We take a matrix which stores the maximum value
	// from M[i]j] to M[n-1][n-1].
	int maxArr[N][N];
	maxArr[N-1][N-1] = M[N-1][N-1];
	int maxv = M[N-1][N-1], maxh = M[N-1][N-1];
	for(int i=N-2;i>=0;i--){
		if(M[N-1][i]>maxv) maxv = M[N-1][i];
		if(M[i][N-1]>maxh) maxh = M[i][N-1];
		maxArr[i][N-1] = maxv;
		maxArr[N-1][i] = maxh;
	}
	for(int i=N-2;i>=0;i--){
		for(int j=N-2;j>=0;j--){
			if(maxArr[i+1][j+1]-M[i][j]>maxDiff) maxDiff = maxArr[i+1][j+1]-M[i][j];
			maxArr[i][j] = max(M[i][j],max(maxArr[i][j+1],maxArr[i+1][j]));
		}
	}
	return maxDiff;
}

int main(){
	 int mat[N][N] = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout<<"Maximum difference is "<<findMaxDiff(mat);
    return 0;
}
