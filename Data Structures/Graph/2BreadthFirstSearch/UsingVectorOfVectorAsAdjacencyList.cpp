// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
    
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
        
        // This BFS is set to begin from node 0 of the graph
        // See UsingMapAsAdjacencyList.cpp for the procedure of
        // BFS traversal
	    unordered_map<int,bool> visited;
        queue<int> bfsQueue;
        vector<int> ans;
        bfsQueue.push(0);
        while(!bfsQueue.empty()){
            int front_element = bfsQueue.front();
            bfsQueue.pop();
            if(!visited[front_element]){
                ans.push_back(front_element);
                visited[front_element] = true;
            }
            for(int i=0;i<adj[front_element].size();i++)
                if(!visited[adj[front_element][i]]) bfsQueue.push(adj[front_element][i]);
        }
        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends



// sample input
// 1
// 5 4
// 0 1 
// 0 2
// 0 3 
// 2 4









