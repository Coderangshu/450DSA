#include <bits/stdc++.h>
using namespace std;
 
#define N 4

//void rotate90Clockwise(int arr[N][N]){
	//int l = N/2;
	//for(int i=0;i<l;i++){
		//swap(arr[i][i],arr[N-1][N-1]);
		//swap(arr[i][N-1],arr[N-1][i]);

void rotate90Clockwise(int arr[N][N])
{
    // printing the matrix on the basis of
    // observations made on indices.
    for (int j = 0; j < N; j++) 
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    return 0;
}
