#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
private:
    map<T,list<pair<T,int>>> adjacencyList;
public:
    void addEdge(T u, T v, int weight, bool bidirectional=true){
        adjacencyList[u].push_back(make_pair(v,weight));
        if(bidirectional)
        adjacencyList[v].push_back(make_pair(u,weight));
    }
    
    // To print Depth First Search Traversal of graph, we start from the
    // given starting node and as before maintain a visited map such that
    // none of the nodes are repeated.
    // For each node encountered push_back that node into the answer and
    // mark it visited in the map, and then one by one take its adjacent nodes
    // and recurse through them to reach the last nodes connected to them and
    // store the nodes in bottom up way upto the current node and then recurse
    // for the next adjacent node and so on until all nodes aren't visited.
    void DFSUtil(T u, unordered_map<T,bool> &visited, vector<T> &ans){
        // base condition
        if(visited[u]) return;
        else{
            // set visited true for the cuurent node
            visited[u] = true;
            // push node into ans vector
            ans.push_back(u);
            // traverse through each adjacent node of current node
            // if not visited then recurse through it to reach the
            // last adjacent node of that node and then bottom uply
            // save the nodes in the ans vector
            for(auto e:adjacencyList[u])
                if(!visited[e.first]) DFSUtil(e.first,visited,ans);
        }
    }
    
    vector<T> DFS(T u){
         // To store the DFS
        vector<T> ans;
        // To keep track of visited nodes while DFSing
        unordered_map<T,bool> visited;
        DFSUtil(u,visited,ans);
        return ans;
    }
};

int main()
{
	Graph<char> g;
	g.addEdge('0', '1',4, 0);
	g.addEdge('0', '7',8, 0);
	g.addEdge('1', '7',11, 0);
	g.addEdge('1', '2',8, 0);
	g.addEdge('7', '8',7, 0);
	g.addEdge('2', '8',2, 0);
	g.addEdge('8', '6',6, 0);
	g.addEdge('2', '5',4, 0);
	g.addEdge('6', '5',2, 0);
	g.addEdge('2', '3',7, 0);
	g.addEdge('3', '3',14, 0);
	g.addEdge('3', '4',9, 0);
	g.addEdge('5', '4',10, 0);
	g.addEdge('7', '6',1, 0);
    
    vector<char> ans = g.DFS('2');
    // Print the DFS traversal from the given node
    for(auto e:ans) cout<<e<<" ";
	return 0;
}
