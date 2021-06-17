#define pb push_back
class Solution {
    
    // DFS Pruning method: Herein we traverse using DFS until we reach destination or 
    // stops equals K as traversing further down that route will increase the stops and
    // won't provide us with the required answer
    
    void DFS(vector<vector<int>>& adj,vector<vector<int>>& cost,int src,
             int dst,int k,int& fare,int totCost,vector<bool>& visited)
    {
        if(k<-1)
            return;
        if(src==dst)
        {
            fare = min(fare,totCost);
            return;
        }
    
        visited[src] = true;
        for(int i=0;i<adj[src].size();++i)
        {
            if(!visited[adj[src][i]] && (totCost+cost[src][adj[src][i]] <= fare))
                DFS(adj,cost,adj[src][i],dst,k-1,fare,totCost+cost[src][adj[src][i]],visited);
        }
        
        visited[src] = false;
    }
public:
    // To implement DFS Pruning
    int findCheapestPriceDFSPrune(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adj(n);
        vector<vector<int>> cost(n+1,vector<int>(n+1));
        
        for(int i=0;i<flights.size();++i)
        {    
            adj[flights[i][0]].pb(flights[i][1]);
            cost[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        vector<bool> visited(n+1,false);    //To break cycles
        int fare = INT_MAX;
        DFS(adj,cost,src,dst,K,fare,0,visited);
        
        if(fare==INT_MAX)
            return -1;
        return fare;
    }
    
    
    
    
    
    
    // Using dijkstra
    int findCheapestPriceDijkstra(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        // construct adjacency list
        vector<pair<int,int>> adj[n];
        for(auto vec:flights){
            adj[vec[0]].pb({vec[1],vec[2]});
        }
        
        // minHeap to keep track of the lowest cost node
        // tuple contains (cost from src, node number, steps upto node)
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> minHeap;
        // pushing src with cost as 0, and steps as 0
        minHeap.push({0,src,0});
        
        // visited array to avoid repetation and cycles
        vector<bool> visited(n,false);
        // marking src as visited
        visited[src] = true;
        
        while(!minHeap.empty()){
            auto[cost,u,steps] = minHeap.top();
            minHeap.pop();
            
            // marking node as visited
            visited[u] = true;
            
            // if u is destination then return the cost
            if(u==dst) return cost;
            
            // if the steps are more than k means further going that path would
            // increase the steps further and that isn't the required answer
            // hence we ignore this path
            if(steps>K) continue;
            
            // peeking into neighbours
            for(auto neighbour:adj[u]){
                auto[v,weight] = neighbour;
                if(!visited[v])
                    minHeap.push({cost+weight,v,steps+1});
            }
        }
        // if reached here means no path exist satiffying the given criteria
        return -1;
    }
    
    
    
    
    
    // Using Bellman Ford Algorithm
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));
        
        //dp[i][j] = Dist to reach j using atmost i edges from src
        
        for(int i = 0; i <= K+1; i++)
            dp[i][src] = 0; // Dist to reach src always zero
        
        // For each node we  traverse through them only k+1 times to reach the destination
        // insted of V-1 times(conventional Bellman Ford)
        for(int i = 1; i <= K+1; i++){
            for(auto &f: flights){
                int u = f[0];
                int v = f[1];
                int w = f[2];
                
                // chooses between the min of current v's cost and the previous
                // cost of u + weight of edge
                // here previous of u because the current u has already been updated to
                // its new value
                if(dp[i-1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
            }
        }
        
        return (dp[K+1][dst] == INT_MAX)? -1: dp[K+1][dst];
    }
};
