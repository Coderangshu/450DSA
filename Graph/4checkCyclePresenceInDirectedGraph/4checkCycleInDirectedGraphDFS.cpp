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
    
    bool isCycleUtil(T u, unordered_map<T,bool> &visited, unordered_map<T,bool> &recStack){
        // base condition
        // if already visited previously but no cycle detected yet then this node won't have
        // any cycle involving it
        if(visited[u]) return false;
        else{
            // Mark the current node as visited and part of recursion stack
            visited[u] = true;
            recStack[u] = true;
            for(auto e:adjacencyList[u]){
                // If the adjacent node to current node isn't visited yet
                // but has a cycle inside it then return true
                if(!visited[e.first] and isCycleUtil(e.first,visited,recStack))
                    return true;
                // Or if this node is visited and is part of the recStack while on processing
                // the current node return true as this node and the current node and/or some
                // nodes in between are forming a cycle
                else if(recStack[e.first]) return true;
            }
            // Reached here means no cycle has been detected that might have involved the current
            // node
        }
        // Thus as no cycle detected for current node and the stack is empty now
        // thus we reset the recStack for this node as false
        recStack[u] = false;
        return false;
    }
    
    bool isCycle(){
        // To keep track of visited nodes while DFSing
        unordered_map<T,bool> visited;
        // To keep track of the nodes present in the
        // recursive stack
        unordered_map<T,bool> recStack;
        for(auto e:adjacencyList){
            // We call isCycleUtil for each node if cycle detected in any of
            // them then return true
            if(isCycleUtil(e.first,visited,recStack)) return true;
        }
        // If reached here means no cycle present in graph
        return false;
    }
};

int main()
{
	Graph<int> g;
	g.addEdge(0,1,4,0);
    g.addEdge(0,2,8,0);
    g.addEdge(1,2,8,0);
    g.addEdge(2,3,8,0);
    // The above makes a non cyclic graph
    // Uncomment below line to connect node
    // 3 to node 0 making it cyclic
    // g.addEdge(3,0,6,0);
    
    bool ans = g.isCycle();
    cout<<ans<<endl;
	return 0;
}
