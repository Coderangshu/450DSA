class Solution {
public:
    
    
    
    
    // Method 1: Using adjacency matrix and DFS/BFS to traverse for each nodes
    // By traversing each nodes we find the components of a graph
    // then check if atleast component-1 redundant edges are present or not
    // if present we return ans as component-1 as that many edges are
    // required to create MST of all components
    
    
    map<int,vector<int>> makeAdj(int n,vector<vector<int>> connections){
        map<int,vector<int>> adjList;
        for(auto v:connections){
            int node1 = v[0], node2 = v[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        return adjList;
    }
    
    int DFS(map<int,vector<int>> adjList, int u, vector<bool> &visited){
        int ans = 0;
        if(visited[u]) return ans;
        else{
            ans++;
            visited[u] = true;
            for(auto e:adjList[u]){
                if(!visited[e]) ans += DFS(adjList,e,visited);
            }
        }
        return ans;
    }
    
    int makeConnected1(int n, vector<vector<int>>& connections) {
        // total edges present in graph
        int E = connections.size();
        
        // if edges are less than n-1(i.e. no. of nodes-1) then no Minimum
        // spanning tree(MST) is possible
        if(E<n-1) return -1;
        
        // Make adjacency list of graph
        map<int,vector<int>> adjList = makeAdj(n,connections);
        vector<bool> visited(n,false);
        
        // components are the individual elements present in a graph
        // components include standalone nodes, connected graph, group
        // of connected graphs
        // Example given graph below:
        
        // 0-------1      3
        //  \     /               5
        //   \   /                 \ 
        //    \ /      4            \ 
        //     2                     6
        
        // This graph has 4 components, (0,1,2),(3),(4),(5,6)
        int components = 0;
        
        for(int i=0;i<n;i++){
            // If not visited node appears means it is a new component
            if(!visited[i]){
                components++;
                // DFS will mark the rest nodes of the current component
                // (if present) as visited
                // Here DFS returns the no. of nodes in each component
                DFS(adjList,i,visited);
            }
        }
        
        // Redundant edges are the edges that which even if remove won't
        // break the connetivity of nodes
        // For example in above graph any of (0,1) or (0,2) or (1,2) edge can
        // be removed without breaking the connectivity of the nodes
        // Also removing any of the above edges makes that component a MST
        
        // n-1 => minimum no.of edges to make MST of all nodes
        // components-1 => minimum no. of edges to make MST of all components
        // thus (n-1)-(components-1) gives the possible MSTs in graph without
        // adding extra edges(i.e. the minimum no. of edges in graph to maintain
        // the connectivity of nodes as present)
        // In above graph this value is 3 means that (0,1,2) and (5,6) maintains
        // connectivity as same with 3 edges
        // Thus we get total redundant nodes as total nodes - ((n-1)-(components-1))
        int redundantEdges = E-((n-1)-(components-1));
        // If redundant nodes are less then total components no connection possible
        if(redundantEdges<components-1) return -1;
        return (components-1);
    }
    
    
    
    
    
    
    
    
    
    
    // Method 2: Using Union Find Algorithm
    // In this method firstly all nodes are standalone then using parent vector
    // we start connecting the nodes to their parents and thus to their ultimate
    // parents, this way we can find the nodes joined to each other and the nodes
    // that are standalone
    
    
    // Keeps track of immediate parent of each node
    // i.e. for connected nodes they will have same parent(may not be immediate),
    // for standalone they will have themselves as the parent
    vector<int> parent;
    
    // Finds parent of given node recursively in parent vector as parent stores
    // the immediated parent of each node so recursion is used to find the ultimate
    // parent
    int find(int v){
        if(parent[v]!=v) return find(parent[v]);
        else return v;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        // total edges present in graph
        int E = connections.size();
        
        // if edges are less than n-1(i.e. no. of nodes-1) then no Minimum
        // spanning tree(MST) is possible
        if(E<n-1) return -1;
        
        
        // Initially we consider every node is standalone
        for(int i=0;i<n;i++) parent.push_back(i);
        
        for(auto connection:connections){
            int node1 = connection[0], node2 = connection[1];
            // Ultimate parent of both node is found
            int p1 = find(node1), p2 = find(node2);
            // If ultimate parent isn't same then, ultimate parent of
            // node1 is assigned as ultimate parent of node2
            // This is naive union set finding
            // this procedure takes linear time to find the disjoint
            // sets, using rank decreases T(n) to logarithmic scale
            // and using rank along with path compression reduces T(n)
            // to constant
            if(p1!=p2) parent[p2] = parent[p1];
        }
        
        int component = 0;
        // Counting the components, nodes with same parent belong to same component
        // thus when node's parent found as same node denotes its a new component's
        // parent, else when not equal means node has some other parent
        for(int i=0;i<n;i++)
            if(parent[i]==i) component++;
        
        // Uncomment to see immediate parent of each node
        // for(int i=0;i<n;i++) cout<<i<<" "<<parent[i]<<endl;
        
        return component-1;
    }
    
    // For input:
    // 12
    // [[1,5],[1,7],[1,2],[1,4],[3,7],[4,7],[3,5],[0,6],[0,1],[0,4],[2,6],[0,3],[0,2]]
    // The parent-node relation comes out to be:
    //                              0
    //                            /   \ 
    //                           3     6
    //                          /
    //                         1
    //                      / / \ \ 
    //                     5 7   2 4
    // Thus the standalone nodes are 8,9,10,11
    // Thus total components are 5
    
};
