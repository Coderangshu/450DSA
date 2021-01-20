// Divide and Rule can also be used for the same.
// Compare recursively with middle element of matrix,
// and dividing the matrix and applying the same in the
// lower and right half - if(target>middle element)
// else search in upper and left half - if(target<middle element)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i;
        for(i=0;i<matrix.size();i++) if(target<matrix[i][0]) break;
        for(int j=0;j<matrix[0].size();j++) if(target==matrix[i-1][j]) return true;
        return false;
    }
};
