#include<bits/stdc++.h>
using namespace std;

void addEdge(map<int,vector<int>> &adjList, int u, int v){
    adjList[u].push_back(v);
}

// The intution is topological sorting
map<int,int> topoSort(int V, map<int,vector<int>> adjList) 
{
	vector<int> in_degree(V,0);
        
     for (int u = 0; u < V; u++)
         for (auto v : adjList[u]) in_degree[v]++;
        
    queue<int> q;
    // currentLevel holds the number of nodes in present in_degree
    // level, for beginning all nodes with in_degree 0 will belong
    // to currentLevel, nextLevel stores the next level of each node
    // in currentLevel while BFSing
    int currentLevel = 0, nextLevel = 0;
    for (int i = 0; i < V; i++){
        if (in_degree[i] == 0){
            q.push(i);
            currentLevel++;
        }
    }
    
    // Map to store the time of completion for each node
    // use unordered_map for faster insertion time, here used
    // map for better representation of answer
    map<int,int> timeTaken;
    // Time taken by first topological order is 1
    int timePassed = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        timeTaken[u] = timePassed;
        
        for (auto e:adjList[u]){
            if (--in_degree[e] == 0){
                q.push(e);
                // this node gets added to queue and to keep
                // track of elements in next level of topological
                // order we increment nextLevel value
                nextLevel++;
            }
        }
        // If currentLevel becomes 0 means current topological
        // order is complete then put nextLevel's count in currentLevel
        // and reset nextLevel and also increment timePassed
        if(--currentLevel==0){
            currentLevel = nextLevel;
            nextLevel = 0;
            timePassed++;
        }
    }
    return timeTaken;
}

int main(){
    map<int,vector<int>> adjList;
    
    // Graph 1:
    // In graph representation all edges point downward
    //              0             1
    //           /  |  \         / \ 
    //          4   3   2       /   8
    //               \ /       /
    //                5       /
    //                 \     /
    //                  6   /
    //                   \ /
    //                    7
    //                    |
    //                    9
    
    int V = 10;
    addEdge(adjList,0, 2);
    addEdge(adjList,0, 3);
    addEdge(adjList,0, 4);
    addEdge(adjList,1, 2);
    addEdge(adjList,1, 7);
    addEdge(adjList,1, 8);
    addEdge(adjList,2, 5);
    addEdge(adjList,3, 5);
    addEdge(adjList,3, 7);
    addEdge(adjList,4, 7);
    addEdge(adjList,5, 6);
    addEdge(adjList,6, 7);
    addEdge(adjList,7, 9);
    
    map<int,int> timeTaken = topoSort(V,adjList);
    for(auto e:timeTaken) cout<<e.first<<" "<<e.second<<endl;
	return 0;
}
