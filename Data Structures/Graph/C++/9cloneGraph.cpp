/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    
    
    
    
    // DFS implementation
    Node* dfs(Node *node, unordered_map<Node*,Node*> &visited){
        if(!node) return NULL;
        // if original node if found in visited as key then return
        // the clone node of it
        if(visited.find(node)!=visited.end()) return visited[node];
        
        // clone the original node
        Node* newNode = new Node(node->val);
        // add original and clone node to visited
        visited[node] = newNode;
        
        // traverse original node's neighbors, for each neighbor
        // add the clone of that neighbor in the current clone node
        for(auto e:node->neighbors)
            newNode->neighbors.push_back(dfs(e,visited));
        // returning the clone node created
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        // visited stores the clone node w.r.t original node
        // as key
        unordered_map<Node*,Node*> visited;
        return dfs(node,visited);
    }
    
    
    
    
    
    
    // BFS implementation
    
    Node* cloneGraph1(Node* node) {
        if(!node) return NULL;
        // visited stores the clone node w.r.t original node
        // as key
        unordered_map<Node*,Node*> visited;
        queue<Node*> q;
        // clone node of current node formed and added to both
        // visited and queue
        visited[node] = new Node(node->val);
        q.push(node);
        // while q not empty
        while(!q.empty()){
            Node * current = q.front();
            q.pop();
            for(auto e:current->neighbors){
                // if current original node's neighbor not visited
                if(visited.find(e)==visited.end()){
                    // clone neighbor
                    visited[e] = new Node(e->val);
                    // add original neighbor to q
                    q.push(e);
                }
                // if visited or after visiting (in above line) now clone of
                // current's neighbor exists thus we add the clone to the clone
                // of current's neigbor vector
                visited[current]->neighbors.push_back(visited[e]);
            }
        }
        return visited[node];
    }
};
