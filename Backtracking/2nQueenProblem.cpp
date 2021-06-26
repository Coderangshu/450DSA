#include<bits/stdc++.h>
using namespace std;




bool isSafe(vector<vector<int>> &board, int row, int column){
	int n = board.size();

	// check all the current row's left cells
	for(int i=0;i<column;i++)
		if(board[row][i]) return false;

	// check all cells on the left upper diagonal 
	for(int i=row,j=column;i>=0 and j>=0;i--,j--)
		if(board[i][j]) return false;

	// check all cells on the left lower diagonal
	for(int i=row,j=column;i<n and j>=0;i++,j--)
		if(board[i][j]) return false;
	
	// if all the above are passes then return true
	return true;
}




bool solveNQUtil(vector<vector<int>> &board, stack<vector<int>> &result, int column){
	// base condition
	// if column == n means we have reached the end
	// of columns in the board and the have been added
	//  queens succesfully, now add the positions
	// of the queens in the board to the result and 
	// return true
	int n = board.size();
	if(column==n){
		vector<int> ans;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(board[i][j])
					ans.push_back(j+1);
		result.push(ans);
		return true;
	}

	// else not reached end thus we try adding a queen to the
	// current column we consider the bool to be returned now
	// as false
	bool res = false;
	
	// traversing through the whole column
	for(int i=0;i<n;i++){
		// if safe to add queen then we add and send
		// for the next column to be checked and also
		// or the res to know if further below we get
		// a true or a false
		if(isSafe(board,i,column)){
			// queen placed in the row
			board[i][column] = 1;
			// check for the next columns
			res = solveNQUtil(board,result,column+1) or res;

			// backtracking to the previous state for checking
			// the next possible combinations
			board[i][column] = 0;
		}
	}
	return res;
}




// Using bit masking to keep track of safe coordinates
// SEE BITMASKING FOLDER'S README TO KNOW THE NOTATION IF
// FORGOTTEN
// To understand each of the bit mask we take the example of n = 6
// 32 Bits used
bool solveNQUtil(vector<vector<int>> &board, stack<vector<int>> &result,
                 int column, int colMask, int upperDiagMask, int downDiagMask){
    
    int n = board.size();
    
    // Bit mask to indicate all columns are filled
    // 00000000000000000000000001000000-1 = 00000000000000000000000000111111
    int allColsFilled = (1<<n)-1;
    
    // if all columns filled means we have got a suitable arrangement
    // of queens, add to result stack
    // read next set of comments to understand the role of colMask
    if(allColsFilled==colMask){
        vector<int> ans;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]) ans.push_back(j+1);
        result.push(ans);
        return true;
    }
    
    // see above function for res's utility
    bool res = false;
    
    // colMask has set bits which have are filled upto the previous column
    // upperDiagMask has set bit which row of this col to block according to upper diagonal
    // downDiagMask has set bit which row of this col to block according to down diagonal
    
    // Example (not displaying the unrequired bits for vivid understanding): 
    // If we are in 3rd column and queen of 2nd column is at 4th row and that of 1st
    // column is at 1st row, then:
    
    // Imagine the mask's bits vertically 
    // RIGHT-LEFT <-> TOP-BOTTOM
    // rows with set bit meaning that row is blocked
    
    // colMask = 001001 indicating 1st & 4th row's queen assigned, rest queens are yet to be set
    // upperDiagMask = 000100 indicating that 3rd row blocked as last col's 4th row has queen
    // downDiagMask = 010000 indicating that 5th row blocked as last col's 4th row has queen
    
    // Now to get the safe bits for this column we do the following:
    
    // Bitwise OR of colMask, upperDiagMask and downDiagMask gives the rows to be avoided
    
    // Bitwise NOT of above gives the safe rows available for the current column
    
    // Bitwise AND with the allColsFilled keeps the bits in the range of n, as for 32 or 64
    // bit OS the bits are 32 bit or 64 bit long respectively thus as allColsFilled has
    // only the bits set for which the rows/cols are to be filled ANDing with it keeps the
    // required safe bits as set rest of 32 or 64 bits are off
    
    // Continuing above example:
    // (001001 | 000100 | 010000) = 011101
    // ~(011101) = 100010
    // 111111 & 111000 = 100010
    // Indicating that 6th and 2nd row are safe fo queen to be placed in this 3rd column
    int safe = allColsFilled & (~(colMask | upperDiagMask | downDiagMask));
    
    // while safe isn't 0, i.e. all rows of current column for which the queen assignement
    // would have been possible isn't exhausted
    while(safe){
        // Getting the right most set bit of safe
        // (the topmost safe row)
        // Space to visualise the required bits
        int sre = safe & (-safe);
        // sre(safeRowExp) = 2 (00000000000000000000000000 000010)
        int safeRow = (int)log2(sre);
        // safeRow = 1
        
        // put queen in this row of this column 
        board[safeRow][column] = 1;
        
        // Now we need to update the colMask, upperDiagMask and downDiagMask
        // new colMask       = 00000000000000000000000000 001011
        // new upperDiagMask = 00000000000000000000000000 000001
        // new downDiagMask  = 00000000000000000000000000 000100
        
        // To update as follows we do the following and send for next column via
        // recursion:
        
        // Bitwise ORing previous colMask and safe row gives us the new colMask
        // Right shift old upperDiagMask to get new one
        // Left shift old downDiagMask to get new one
        
        // Continuing above example(not displaying the unrequired bits for vivid understanding):
        // new colMask = (001001 | 000010) = 001011
        // new upperDiagMask = 000010 >> 1 = 000001
        // new downDiagMask  = 000010 << 1 = 000100
        res = solveNQUtil(board,result,column+1,(colMask|sre),sre>>1,sre<<1) or res;
        
        // set the right most set bit of safe to 0 as it has already been processed
        safe = safe & (safe-1);
        
        // reset queen from current location of board to get processed
        // in further calls using the arrangement upto the previous pattern
        // BACKTRACKING
        board[safeRow][column] = 0;
    }
    return res;
}


stack<vector<int>> nQueen(int n){
	// To store the result, i.e. the row number
	// for the n rows where the queens are to be
	// placed (1 indexed) from the leftmost column
	// to the right
    // Here we use stack to get the actual(lexicographic)
    // order of the vectors as the recursion stack reverses
    // the order of the possible queen arrangements
	stack<vector<int>> result;
	
	// Create board
	vector<vector<int>> board(n,vector<int>(n,0));

	// solve the problem
	// return stack
	
    // Use normal backtracking method
//     solveNQUtil(board,result,0);
    
    // Use bit masking with backtracking
    // bit masking makes the above algorithm time efficient
    solveNQUtil(board,result,0,0,0,0);
    
	return result;
}

int main(){
	int n = 4;
	stack<vector<int>> ans = nQueen(n);

    while(!ans.empty()){
        cout<<"[ ";
        for(auto e:ans.top()) cout<<e<<" ";
        cout<<"]"<<endl;
        ans.pop();
    }
	return 0;
}
