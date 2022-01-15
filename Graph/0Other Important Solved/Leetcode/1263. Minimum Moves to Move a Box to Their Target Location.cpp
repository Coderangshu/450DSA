// see https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/discuss/1471512/Fast-easy-to-understand-solution-using-2-BFSs-complete-intuition-and-explanation for better explantion

class Solution {
public:
    
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    
    bool isValid(vector<vector<char>>&grid, int x, int y){
        int m = grid.size(), n = grid[0].size();
        // int i = x*n+y;
        // if(i==29) cout<<(x>=0 and y>=0 and x<m and y<n and grid[x][y]!='#')<<endl;
        return (x>=0 and y>=0 and x<m and y<n and grid[x][y]!='#');
    }
    
    bool canAccess(vector<vector<char>>&grid, int dest, int src, int box){
        int m = grid.size(), n = grid[0].size();
        
        vector<bool> visited(m*n,false);
        visited[src] = true;
        
        // mark the location of box as blocked as stkp can't travel there
        grid[box/n][box%n] = '#';
        
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int cp = q.front();
            q.pop();
            if(dest==cp){grid[box/n][box%n] = '.';return true;}
            for(auto e:dir){
                int nx = cp/n+e[0], ny = cp%n+e[1];
                int np = nx*n+ny;
                if(np>=0 and np<m*n){
                    if(visited[np]) continue;
                    visited[np] = true;
                    if(!isValid(grid,nx,ny)) continue;
                    q.push(np);
                }
            }
        }
        grid[box/n][box%n] = '.';
        return false;
    }
    
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // get position of storekeeper, box and target
        // and mark those points as open path, i.e. '.'
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='.') cout<<i*n+j<<"\t";
                else cout<<grid[i][j]<<"\t";
            }
                cout<<endl;
        }
        int stkp, box, tar;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='S') {stkp = i*n+j;grid[i][j]='.';}
                else if(grid[i][j]=='B') {box = i*n+j;grid[i][j]='.';}
                else if(grid[i][j]=='T') {tar = i*n+j;;grid[i][j]='.';}
            }
        }
        if(box==tar) return 0;
        
        // BFSing for box to target
        
        // queue stores the stkp and the box locations
        // as both needs to be kept track of while traversing
        // for each location of the box
        queue<pair<int,int>> q;
        q.push({box,stkp});
        
        // keeping track of visited nodes for the stkp and 
        // the box simultaneously using a string
        unordered_set<string> visited;
        visited.insert(to_string(stkp)+" "+to_string(box));
        
        int pushes = 0;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                auto [bo,stkpo] = q.front();
                q.pop();
                if(bo==tar) return pushes;
                for(auto e:dir){
                    int nbx = bo/n+e[0], nby = bo%n+e[1];
                    int nstkpx = bo/n-e[0], nstkpy = bo%n-e[1];
                    int nstkp = nstkpx*n+nstkpy, nb = nbx*n+nby;
                    if(nstkp>=0 and nb>=0 and nstkp<m*n and nb<m*n){
                        string key = to_string(nstkp)+" "+to_string(nb);
                        if(visited.find(key)!=visited.end()) continue;
                        if(!isValid(grid,nbx,nby) or !isValid(grid,nstkpx,nstkpy)) continue;
                    
                        // if stkp can get to the position from where he can push the box
                        // push new position of box and new position of stkp (old position of box)
                        // into the queue
                        if(canAccess(grid,nstkp,stkpo,bo)){
                            visited.insert(key);
                            q.push({nb,bo});
                        }
                    }
                }
            }
            // if reached this point means 1 push has been performed
            // and the box is 1 step closer to the target
            pushes++;
        }
        return -1;
    }
};