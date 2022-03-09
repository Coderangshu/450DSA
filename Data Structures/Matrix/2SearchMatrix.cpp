// Use Binary Search
class Solution {
private:
    int binarySearch(vector<vector<int>>& matrix, int target){
        int low = 0, high = matrix.size()-1 ,ans = -1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(matrix[mid][0]<=target){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
    
    int binarySearch(vector<vector<int>>& matrix, int target, int rowInd){
        int low = 0, high = matrix[0].size()-1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(matrix[rowInd][mid]==target) return mid;
            else if(matrix[rowInd][mid]<target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ri = binarySearch(matrix,target);
        if(ri<0) return false;
        int ci = binarySearch(matrix,target,ri);
        if(ci<0) return false;
        return true;
    }
};
