class UnionFind{
private:
    unordered_map<int,int> parent;
    
public:
    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void Union(int u, int v){
        if(parent.count(u)==0) parent[u] = u;
        if(parent.count(v)==0) parent[v] = v;
        int pu = findParent(u), pv = findParent(v);
        if(pu!=pv) parent[pv] = pu;
    }
    
    // get the groups with common parent
    unordered_map<int,vector<int>> getGroups(){
        // key->parent, value->vector of all child under parent
        unordered_map<int,vector<int>> groups;
        for(auto [u,_]:parent) groups[findParent(u)].push_back(u);
        return groups;
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        // grouping cells according to their values and also sorting in the
        // process according to the values (done in map by default)
        map<int,vector<pair<int,int>>> groupCellsByValue;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                groupCellsByValue[matrix[i][j]].push_back({i,j});
        
        // stores the rank of each row and col iteratively,
        // for each iteration the rank updates and then assigned
        // to the cells of concern present in that row,col
        vector<int> rank(rows+cols,0);
        for(auto [_,cells]:groupCellsByValue){
            UnionFind uf;
            // iteratively unioning row  and col of each cell found under the same group
            // c+rows is done to maintain the 1D essence of rank vector
            for(auto [r,c]:cells) uf.Union(r,c+rows);
            
            // obtaining groups of the above unioned cells, this groups represent that
            // each of the cell in them is either having same row or same col, thus
            // will belong to the same rank
            // find the max rank of all row and cell then +1 done and rank updated for all
            // the rows and cols of the group of same valued elements (group of groupCellsByValue)
            for(auto [_,group]:uf.getGroups()){
                // getting max rank of all row and col of this group
                int maxPrevRank = 0;
                for(int i:group) maxPrevRank = max(maxPrevRank,rank[i]);
                // updating the new rank for all row and col of this group
                for(int i:group) rank[i] = maxPrevRank+1;
            }
            // update matrix with the ranks obatained for this group of cells
            for(auto [r,c]:cells) matrix[r][c] = rank[r]; // or rank[c+rows] as both same
        }
        return matrix;
    }
};
