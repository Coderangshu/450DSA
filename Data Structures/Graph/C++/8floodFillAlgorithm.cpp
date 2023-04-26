class Solution {
public:
    
    // Method I: Recursion
    
    // A recursive function to replace previous color 'prevColor' at  '(x, y)'
    // and all surrounding pixels of (x, y) with new color 'newColor' and
    void floodFillUtil(vector<vector<int>> &image, int x, int y, int prevColor, int newColor)
    {
        // Base cases
        // When point out of image
        if (x<0 or x>=image.size() or y<0 or y>=image[0].size()) return;
        // When pixel is not the color to be replaced
        if (image[x][y] != prevColor) return;
        // When pixel color is already the new color
        if (image[x][y] == newColor) return;

        // Replace the color at (x, y)
        image[x][y] = newColor;

        // Recur for north, east, south and west
        floodFillUtil(image, x+1, y, prevColor, newColor);
        floodFillUtil(image, x-1, y, prevColor, newColor);
        floodFillUtil(image, x, y+1, prevColor, newColor);
        floodFillUtil(image, x, y-1, prevColor, newColor);
    }
    
    vector<vector<int>> floodFill1(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevColor = image[sr][sc];
        floodFillUtil(image, sr, sc, prevColor, newColor);
        return image;
    }
    
    
    
    
    // Method II: Using BFS
    
    // Check is pixel in image
    bool isSafe(int x, int y, int prevColor, int newColor, vector<vector<int>> image){
        // When point out of image
        if (x<0 or x>=image.size() or y<0 or y>=image[0].size()) return false;
        // When pixel is not the color to be replaced
        if (image[x][y] != prevColor) return false;
        // When pixel color is already the new color
        if (image[x][y] == newColor) return false;
        return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        // Visiing array
        vector<vector<bool>> visited;

        // Creating queue for bfs
        queue<pair<int,int>> q;

        // Saving previous color
        int preColor = image[sr][sc];

        // Pushing pair of {x, y}
        q.push({sr,sc});

        // Marking {x, y} as visited
        visited[sr][sc] = true;

        // Untill queue is empty
        while (q.empty() != 1){
            // Extrating front pair
            pair<int, int> coord = q.front();
            // Poping front pair of queue
            q.pop();

            int x = coord.first;
            int y = coord.second;
            image[x][y] = newColor;

            // For Upside Pixel or Cell
            if (isSafe(x+1,y,preColor,newColor,image) and !visited[x+1][y]){
                q.push({x+1,y});
                visited[x+1][y] = true;
            }

            // For Downside Pixel or Cell
            if (isSafe(x-1,y,preColor,newColor,image) and !visited[x-1][y]){
                q.push({x-1,y});
                visited[x-1][y] = true;
            }

            // For Right side Pixel or Cell
            if (isSafe(x,y+1,preColor,newColor,image) and !visited[x][y+1]){
                q.push({x,y+1});
                visited[x][y+1] = true;
            }

            // For Left side Pixel or Cell
            if (isSafe(x,y-1,preColor,newColor,image) and !visited[x][y-1]){
                q.push({x,y-1});
                visited[x][y-1] = true;
            }
        }
        return image;
    }
    
    
    
    
    
    
    
};
