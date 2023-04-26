// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
        
    // We make an adjacency list of the graph of the K letters of the
    // alien dictionary then using topological sort we find the order
    // of the letters in alien dictionary from the adjacency list
    
    
    void makeAdj(vector<int> adj[], string dict[], int N){
        // To make adjecency list we surf through consecutive
        // words in the dict, for the first non-matching character
        // in those words we put the char of second word in the list
        // of the firt word's char
        for(int i=0;i<N-1;i++){
            string word1 = dict[i], word2 = dict[i+1];
            for(int j=0;j<min(word1.length(),word2.length());j++){
                char c1 = word1[j], c2 = word2[j];
                if(c1!=c2){
                    adj[c1-'a'].push_back(c2-'a');
                    break;
                }
            }
        }
    }
    
    vector<int> topoSort(vector<int> adj[], int K){
        vector<int> in_degree(K,0);
        // Counting in degree for each node in graph
        for(int i=0;i<K;i++)
            for(auto v:adj[i]) in_degree[v]++;
            
        vector<int> ans;
        
        queue<int> q;
        // Nodes with inDegree 0 are added to q
        for(int i=0;i<K;i++) if(in_degree[i]==0) q.push(i);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            // decrementing each adjacent node's inDegree
            // if it becomes 0 push to queue
            for(auto e:adj[front])
                if(--in_degree[e]==0) q.push(e);
        }
        return ans;
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        
        makeAdj(adj,dict,N);
        vector<int> topoSorted = topoSort(adj,K);
        
        string ans = "";
        for(auto e:topoSorted) ans += 'a'+e;
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
