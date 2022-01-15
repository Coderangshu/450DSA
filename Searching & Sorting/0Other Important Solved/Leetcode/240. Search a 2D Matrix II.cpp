class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<1 or matrix[0].size()<1) return false;
        int col = matrix[0].size()-1;
        int row = 0;
        while(col>=0 and row<matrix.size()){
            if(target==matrix[row][col]) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};