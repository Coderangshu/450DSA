// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends


class Solution 
{
    public:
    
    // Function to check if k is valid input at grid[i][j]
    
    // checks the particular row, column and the small square
    bool isValid(int grid[N][N], int i, int j, int k){
        // Instead of running 3 loops individually for each of them
        // we do all the 3 task in the same loop from 0 to 8
        for(int u=0;u<N;u++){
            // checks the row
            if (grid[i][u]==k) return false;
            // checks the column
            if (grid[u][j]==k) return false;
            // checks the small square to which the current cell
            // belongs to
            if (grid[3*(i/3)+u/3][3*(j/3)+u%3]==k) return false;
        }
        // if all above condition passes return true
        return true;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudokuI(int grid[N][N])
    { 
        // Your code here
        
        // traversing through 9x9 grid
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                // if a grid has 0 means its empty
                // we need to fill it
                if(grid[i][j]==0){
                    // checking 1-9 if they can be placed in
                    // this empty cell
                    for(int k=1;k<=9;k++){
                        // if can be placed
                        if(isValid(grid,i,j,k)){
                            // we put number
                            grid[i][j] = k;
                            // send grid to fill the rest cells
                            // if return true means they have been
                            // filled thus we return true fir this
                            // number and go to the previous recursion
                            // call that was made before this
                            if(SolveSudokuI(grid)) return true;
                            // if returned false means this number isn't
                            // suitable in this cell, thus we backtrack
                            // by reseting this cell and going on with iteration
                            // using the other numbers
                            else grid[i][j] = 0;
                        }
                    }
                    // if reached here means that none 1-9 could satisfy
                    // the cell thus false is returned meaning no suitable
                    // solution for the given sudoku
                    return false;
                }
            }
        }
        return true;
    }
    
    // a faster approach then above
    // Instead of starting from beginning for each iteration
    // start from the next col in that row, this optimizes the
    // recursive function a lot
    bool SolveSudoku(int board[N][N], int row=0, int col=0){
        for(int i=row;i<9;i++){
            for(int j=col;j<9;j++){
                if(board[i][j]==0){
                    for(char k=1;k<=9;k++){
                        if(isValid(board,i,j,k)){
                            board[i][j] = k;
                            if(SolveSudoku(board,i,j+1)) return true;
                            board[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
            // after the end of the col from
            // where started col needs to be
            // reset to 0 after each row is checked
            col = 0;
        }
        return true;
    }

    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        
        // the above 2d matrix passing method passes the location
        // of the original matrix thus changes made in it remains
        // in it, we just simply print the filled sudoku puzzle
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
