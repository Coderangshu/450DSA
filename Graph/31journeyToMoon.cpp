#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */







// Method: We need to find the components in the graph and the number of nodes in each of
// them, using the no. of nodes in each components we calculate the no. of combinations in
// which we can choose a astronaut from each of the components.
// To do so we first assume that all possible choices of picking astronauts is nC2(i.e. n*(n-1)/2)
// as the answer then in each component we find the number of pairs that can be formed inside them
// and as we need to select only one astronaut from each component thus we have to remove these 
// pairs thus subtracting these pairs from the answer.


// For finding the components and the number of nodes in each component we use either union find set
// or DFS




// Using union find set

struct stats{
    ll parent,rank;
};

ll findParent(vector<stats> &status, ll node){
    if(status[node].parent!=node) 
        return status[node].parent = findParent(status, status[node].parent);
    else return status[node].parent;
}

void Union(vector<stats> &status, ll x, ll y){
    int px = findParent(status, x), py = findParent(status, y);
    if(status[px].rank<status[py].rank) status[px].parent = py;
    else if(status[py].rank<status[px].rank) status[py].parent = px;
    else{
        status[py].parent = px;
        status[px].rank++;
    }
}

// return the number of nodes under each of the node
vector<ll> getNoOfNodesInComponents(vector<ll> adj[], ll n){
    vector<stats> status(n);
    for(ll i=0;i<n;i++){
        status[i].parent = i;
        status[i].rank = 0;
    }
    for(ll u=0;u<n;u++){
        for(auto v:adj[u]){
            ll pv = findParent(status, v), pu = findParent(status, u);
            if(pv!=pu) status[pv].parent = pu; //Union(status, pu, pv);
        }
    }

    vector<ll> ans(n,0);
    for(auto e:status){
        ans[e.parent]++;
    }
    return ans;
}




// Using DFS

void DFS(long long u, vector<ll> adj[], ll n, vector<bool> &visited, ll &noOfNodes){
    if(visited[u]) return ;
    visited[u]=true;
    // noOfNodes counts the nodes in the current component
    noOfNodes++;
    for(auto i: adj[u])
        if(!visited[i])
            DFS(i,adj,n,visited,noOfNodes);
}




ll journeyToMoon(ll n, vector<vector<int>> astronaut) {
    vector<ll> adj[n];
    for(auto vec:astronaut){
        ll u = vec[0], v = vec[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Taking all pairs as answer
    ll ans = n*(n-1)/2;
    
    // For using union find(providing inconsistent answer)
    
    // vector<ll> nOfNodes = getNoOfNodesInComponents(adj, n);
    
    // for(auto e:nOfNodes){
    //     ans -= e*(e-1)/2;
    // }
    
    
    
    // for using DFS
    
    vector<bool> visited(n,false);
    ll noOfNodes = 0;
    for(ll i=0;i<n;i++){
        noOfNodes = 0;
        DFS(i,adj,n,visited,noOfNodes);
        ans -= noOfNodes*(noOfNodes-1)/2;
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    ll result = journeyToMoon(n, astronaut);
    
    cout<< result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
