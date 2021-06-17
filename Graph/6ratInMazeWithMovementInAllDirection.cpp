// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(vector<vector<int>> m, int n, int x, int y, vector<vector<bool>> &visited){
        // x or y isn't out of bound, or (x,y) visited previously or path is blocked
        if(x==-1 or x==n or y==-1 or y==n or visited[x][y] or m[x][y]==0) return false;
        return true;
    }
    
    // This is the Backtracking function for each node it encounters it checks if it is safe
    // or not is safe then mark it as visited then check in all four directions in Down,Left,
    // Right,Up order as this will give the answer in lexicographical sequence.
    
    // For each movement add movement to path string then recursively call this function
    // to check and complete the rest of the path, after process is over remove the last
    // movement from the path string(part of backtracking) and move on to the next movement
    // in the end when all 4 movements are checked then mark the current node as not visited
    // (second part of backtracking) making it clear for other paths to be checked
    void findPathUtil(vector<vector<int>> m, int n, int x, int y, string &path,
                        vector<string> &ans, vector<vector<bool>> &visited){
        // base condition
        // This will check the initial point
        // if current block is safe or not
        if(!isSafe(m,n,x,y,visited))return;
        
        // If reach the last cell (n-1, n-1) then store the path and return
        if(x==n-1 and y==n-1){
            ans.push_back(path);
            return;
        }
        
        // Mark the cell as visited
        visited[x][y] = true;
        
        // Try for all the 4 directions (down, left, right, up) in the given order 
        // to get the paths in lexicographical order
        
        // Check if downward move is valid
        if (isSafe(m,n,x+1,y,visited)){
            // Add step to path
            path.push_back('D');
            // go for next step
            findPathUtil(m,n,x+1,y,path,ans,visited);
            // Remove step from path after it is processed
            path.pop_back();
        }
        
        // Check if left move is valid
        if (isSafe(m,n,x,y-1,visited)){
            // Add step to path
            path.push_back('L');
            // go for next step
            findPathUtil(m,n,x,y-1,path,ans,visited);
            // Remove step from path after it is processed
            path.pop_back();
        }
        
        // Check if right move is valid
        if (isSafe(m,n,x,y+1,visited)){
            // Add step to path
            path.push_back('R');
            // go for next step
            findPathUtil(m,n,x,y+1,path,ans,visited);
            // Remove step from path after it is processed
            path.pop_back();
        }
        
        // Check if upward move is valid
        if (isSafe(m,n,x-1,y,visited)){
            // Add step to path
            path.push_back('U');
            // go for next step
            findPathUtil(m,n,x-1,y,path,ans,visited);
            // Remove step from path after it is processed
            path.pop_back();
        }
        
        // Mark the cell as unvisited for other possible paths
        visited[x][y] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        findPathUtil(m,n,0,0,path,ans,visited);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
