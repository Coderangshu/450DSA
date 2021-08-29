#include <bits/stdc++.h>
using namespace std;

// method returns minimum cost to break board into m*n squares
int minimumCostOfBreaking(int X[], int Y[], int m, int n){
	// Cost calculation is number of oriented pieces*cost of cut in that orientation
    // thus to cut in minimum cost first cut at the large cost places then gradually
    // cut at smaller places
    
	// sort the horizontal & vertical cost in reverse order
	sort(X, X + m, greater<int>());
	sort(Y, Y + n, greater<int>());

	// initialize current pieces in both horizontal and vertical as 1
	int hzntl = 1, vert = 1;

    // to store ans
    int res = 0;
    
	// loop until one or both cost array are processed
	int i = 0, j = 0;
	while(i<m and j<n){
        // taking the cut which has higher cost of both
        // the horizontal or vertical
        
        // if vertical cost is more
		if (X[i]>Y[j]){
			res += X[i] * vert;
			// increase current horizontal part count by 1
            // (as 1 vertical cut makes 2 horizontal pieces)
			hzntl++;
			i++;
		}
		// if horizontal cost is more
		else{
			res += Y[j] * hzntl;
			// increase current vertical part count by 1
			vert++;
			j++;
		}
	}

	// loop for vertical array, if remains
	while (i < m)
		res += X[i++] * vert;

	// loop for horizontal array, if remains
	while (j < n)
		res += Y[j++] * hzntl;

	return res;
}

// Driver code to test above methods
int main()
{
	int m = 6, n = 4;
	int X[m-1] = {2, 1, 3, 1, 4};
	int Y[n-1] = {4, 1, 2};
	cout << minimumCostOfBreaking(X, Y, m-1, n-1);
	return 0;
}
