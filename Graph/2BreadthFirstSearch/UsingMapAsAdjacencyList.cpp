#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
private:
    map<T,vector<pair<T,int>>> adjacencyList;
public:
    void addEdge(T u, T v, int weight, bool bidirect=true){
        adjacencyList[u].push_back(make_pair(v,weight));
        if(bidirect)
        adjacencyList[v].push_back(make_pair(u,weight));
    }
    
    // traversal of graph beginning from given node u
    vector<T> BFS(T u){
        unordered_map<T,bool> visited;
        queue<T> bfsQueue;
        vector<T> ans;
        // Once a node visited is not repeated again
        // as is a cycle present in graph it would keep
        // repeating thus once a node is travelled we put
        // true in its visited map.
        
        
        // We push the first node in the queue
        bfsQueue.push(u);
        while(!bfsQueue.empty()){
            // Front element poped from queue
            T front_element = bfsQueue.front();
            bfsQueue.pop();
            
            // If the node isn't visited then push to answer
            // vector and set visited of this node as true
            if(!visited[front_element]){
                ans.push_back(front_element);
                visited[front_element] = true;
            }
            // loop through the adjacent nodes of the current node
            // if not visited then add to queue to be processed in the
            // next iterations.
            for(auto e:adjacencyList[front_element])
                if(!visited[e.first]) bfsQueue.push(e.first);
        }
        return ans;
    }
    
    void printBFS(T u){
        vector<T> ans = BFS(u);
        for(auto e:ans) cout<<e<<"->";
        cout<<"EXIT"<<endl;
    }
};

int main(){
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
    g.printBFS('7');
}
