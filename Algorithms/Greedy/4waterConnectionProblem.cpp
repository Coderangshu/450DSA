class Solution
{
    public:
     
    // Array source stores the starting end of pipe
    vector<int> source;
    
    // Array destination stores the ending vertex of pipe
    vector<int> destination;
    
    // Array diameter stores the value of diameters between two pipes
    vector<int> diameter;
    
    // DFSing through all pipes from the start house
    // to the last house
    int findLastHouse(int i, int &dia){
        // last house i.e. the house with the tap
        // will satisfy the following conditions:
        // (1) has a source
        // (2) do not have a destination
        if(source[i]!=-1 and destination[i]==-1) return i;
        // else this is a intermediatory house with both
        // source and destination in it, thus go to next destination
        // also get the min diameter pipe in the path
        dia = min(dia,diameter[i]);
        return findLastHouse(destination[i],dia);
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> start,vector<int> end,vector<int> dia)
    {
        // code here
        source.assign(n,-1);
        destination.assign(n,-1);
        diameter.assign(n,-1);
        
        int i = 0;
        while(i<p){
            // For ith pipe
            // ending house stores the source house
            source[end[i]-1] = start[i]-1;
            // source house stores the ending house
            destination[start[i]-1] = end[i]-1;
            // source house stores the diameter of pipe starting
            // from it
            diameter[start[i]-1] = dia[i];
            i++;
        }
        
        vector<vector<int>> ans;
        
        for(i=0;i<n;i++){
            // For tank the ith house should satisfy following:
            // (1) has a destination
            // (2) do not have a source
            if(destination[i]!=-1 and source[i]==-1){
                int minDiaPipe = INT_MAX;
                int finalDestination = findLastHouse(i,minDiaPipe);
                ans.push_back({i+1,finalDestination+1,minDiaPipe});
            }
        }
        return ans;
    }
};
