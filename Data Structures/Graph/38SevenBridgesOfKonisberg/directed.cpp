// Eulerian Path:    All edges travelled only once, and starting and ending nodes are different
// Eulerian Circuit: All edges travelled only once, and starting and ending nodes are same

// 4 flavours of Eulerian path/circuit:


//                   |             Eulerian Path            |             Eulerian Circuit
// ---------------------------------------------------------------------------------------------------
// Undirected Graph  | Every vertex has even degree         | Every vertex has even degree or exactly
//                   |                                      | 2 vertices with odd degree, this 2 will
//                   |                                      | be the starting and ending of the path
//----------------------------------------------------------------------------------------------------
// Directed Graph    | Every vertex has equal inDegree and  | Atmost 1 vertex has outDegree-inDegree=1
//                   | outDegree                            | and atmost 1 with inDegree-outDegree=1
//                   |                                      | rest all must have equal number of 
//                   |                                      | inDegree and outDegree

// To understand better : https://youtu.be/xR4sGgwtR2I (Eularian Path Theory)
//                        https://youtu.be/8MpoO2zA2l4 (Eularian Path finding using modified DFS)

#include<bits/stdc++.h>
using namespace std;


class Solution{
private:
    // can use queue or stack or vector for adjacency list,
    // we need to remove each visited node after being added
    // to the path, in this DFS we do not backtrack as we
    // check in the beginning if the path is possible or not,
    // if eulerian than we can find the path from the starting
    // node which is also found during  the eulerian path existence check
    unordered_map<int,queue<int>> adj;
    unordered_map<int,int> inDegree,outDegree;
    vector<int> ans;
    int start = -1;

    // conditions for a graph to contain Eulerian path
    // 1. all nodes have even degree
    // 2. only 2 nodes with odd degree (or 0 is eulerian cycle exists)
    bool doesEulerianPathExist(){
        int inGTOut = 0, outGTIn = 0;
        for(auto &p:adj){
            // If node has no in and out degree means
            // graph is disconnected thus no Eulerian 
            // path is possible
            if(inDegree[p.first]==0 and outDegree[p.first]==0) return false;
            else{
                if(inDegree[p.first]!=outDegree[p.first]){
                    // if outDegree is more than inDegree than
                    // this is starting point of path
                    if(outDegree[p.first]>inDegree[p.first]){
                        start = p.first;
                        outGTIn++;
                    }
                    else if(outDegree[p.first]<inDegree[p.first]) inGTOut++;
                }
            }
        }
        // out and in for the odd degree nodes must exceed by just 1
        if(outGTIn==1 and inGTOut==1) return true;
        else return false;
    }

    // function to print Eulerian path using postorder dfs
    void printEulerianPathUtil(int parent){
        while(!adj[parent].empty()){
            int child = adj[parent].front();
            adj[parent].pop();
            // first adding all paths from child to grandchild
            // and so on, as from parent to multiple children
            // we need to get to the parent multiple times
            // which would be obtained from the grandparents
            // and so on....
            printEulerianPathUtil(child);
        }
        ans.push_back(parent);
    }
public:
    void addEdge(int u,int v){
        adj[u].push(v);
        outDegree[u]++;
        inDegree[v]++;
    }

    void printEulerianPath(){
        if(doesEulerianPathExist()){
            // if all nodes have even degree then assign
            // start as any node (here the first of adj list)
            start = (start==-1)?adj.begin()->first:start;
            printEulerianPathUtil(start);
            // we get the answer in reversed order due to postorder dfs
            reverse(ans.begin(),ans.end());
            cout<<"The Eulerian path is: ";
            for(auto &e:ans) cout<<e<<"->";
            cout<<"END"<<endl;
        }
        else cout<<"No Eulerian Path Exists";
    }
};

int main(){
    // Graph 1:
    //      
    //      node 1 has a self edge
    //      
    //        --
    //       /  \ 
    //      /   <|
    //     1---->3------>5
    //     |>|>  |     / |>
    //      | \  |    /   |
    //      |  \ |   /    |
    //      |   \<| |>    |
    //      0<---->2----->4
    // 
    // 
    //

    Solution obj = Solution();
    obj.addEdge(0,1);
    obj.addEdge(0,2);
    obj.addEdge(1,1);
    obj.addEdge(1,3);
    obj.addEdge(1,3);
    obj.addEdge(2,0);
    obj.addEdge(2,1);
    obj.addEdge(2,4);
    obj.addEdge(3,2);
    obj.addEdge(3,5);
    obj.addEdge(4,5);
    obj.addEdge(5,2);
    
    obj.printEulerianPath();
    return 0;
}
