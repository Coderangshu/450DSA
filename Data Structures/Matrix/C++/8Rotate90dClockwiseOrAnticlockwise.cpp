#include <bits/stdc++.h>
using namespace std;


/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/

void rotate90Clockwise(int **matrix, int n) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}


/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/

void rotate90Anticlockwise(int **matrix, int n) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}


void printMatrix(int **arr, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    int arr[4][4] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr,4);
    return 0;
}
