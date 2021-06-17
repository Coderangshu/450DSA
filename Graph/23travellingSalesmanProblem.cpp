#include<bits/stdc++.h>
using namespace std;




// Method 1: Taking all permutations from source and calculating
//           all paths and returning the lowest cost path.
//           T(n) = O(n!)




int travellingSalesman(vector<vector<int>> graph, int V,int src){
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != src)
            vertex.push_back(i);
 
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    // store the minimum cost path
    vector<int> lowPath;
    // compute and add weight to total path untill all permutations
    // of the vertices are over
    do {
        // store current Path weight(cost)
        int current_pathweight = 0;
 
        // compute current path weight
        int k = src;
        // Traversing from src to end node and calculating
        // cost for this path
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        // adding the cost from last to source
//         current_pathweight += graph[k][src];
 
        // update minimum
        if(current_pathweight<min_path){
            min_path = current_pathweight;
            lowPath = vertex;
        }
 
    } while (next_permutation(vertex.begin(), vertex.end()));
 
    // Printing the lowest cost path
    cout<<src<<"->";
    for(auto e:lowPath) cout<<e<<"->";
    cout<<src<<endl;
    
    // returning the lowest cost
    return min_path;
}

pair<stack<int>,int> travellingSalesmanRecursion(vector<vector<int>> graph, vector<bool> &visited, int src){
    // base condition
    // Getting count of visited nodes if 1 then we know this is the last node
    // we push it to the path stach and return cost of src to node
    int count = 0, index = 0;
    for(int i=0;i<graph.size();i++){
        if(!visited[i]){
            count++;
            index = i;
        }
    }
    if(count==1){
        stack<int>path;
        path.push(index);
        return make_pair(path,graph[src][index]);
    }
    
    else{
        // stores the minCost of total path till now
        int minCost = INT_MAX;
        // pair to get the values from the last recursive call
        pair<stack<int>,int> ans;
        // to store the most updated path till now
        stack<int> path;
        for(int i=0;i<graph.size();i++){
            // if the node isn't itself and not visited yet
            if(graph[0][i]!=0 and !visited[i]){
                // node is the next in path
                int nsrc = i;
                // marked true
                visited[i] = true;
                // made recursive call on the sub problem with the current
                // node as the new source
                ans = travellingSalesmanRecursion(graph,visited,nsrc);
                // if the cost of the path formed is lesser than the current
                // cost then update the minCost and the path
                if(graph[src][i]+ans.second<minCost){
                    minCost = graph[src][i]+ans.second;
                    path = ans.first;
                    path.push(nsrc);
                }
                // visited marked as false for the traversal by the future nodes
                visited[i] = false;
            }
        }
        return {path,minCost};
    }
}

int main(){
    
    int V= 4;
    vector<vector<int>> graph = {{0,10,15,20},
                                 {12,0,5,25},
                                 {9,35,0,30},
                                 {23,32,18,0}};
                                 
    cout<<travellingSalesman(graph,V,0)<<endl;
    
    vector<bool> visited(V,false); 
    visited[0] = true;
    pair<stack<int>,int> ans = travellingSalesmanRecursion(graph,visited,0);
    ans.first.push(0);
    for(int i=0;i<V;i++){
        cout<<ans.first.top()<<"->";
        ans.first.pop();
        if(ans.first.size()==1) ans.second+graph[ans.first.top()][0];
    }
    cout<<0<<endl;
    cout<<ans.second<<endl;
	return 0;
}
