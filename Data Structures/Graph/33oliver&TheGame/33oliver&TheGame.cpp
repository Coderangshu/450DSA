// Method: We maintain two timings for each node in and out, and traverse DFSely
// when a node is come across for the first time we enter the inTime and go to its
// sub nodes then after all the subnodes are visited and we reach the node again
// we mark its outTime
// Then we need to check the relation between 2 nodes as mentioned in question x
// and y
// If from x we move towards king then we check whether x is in subtree of y
// else if x moves away from king then we check whether y is in subtree of x
// if not then x cannot reach y




#include<bits/stdc++.h>
using namespace std;

void dfs(int src,int parent,vector<int> adj[],
		vector<int> &inTime,vector<int> &outTime, int &timer){
    // mark intime of current node
    inTime[src] = ++timer;
    // traverse through subtree of current node
    for(auto x:adj[src]){
        if(x!=parent){
            dfs(x,src,adj,inTime,outTime,timer);
        }
    }
    // mark outTime of current node
    outTime[src] = ++timer;
}

// To check whether x is in y's subtree
bool check(int x,int y,vector<int> &inTime,vector<int> &outTime){
    // x intime should be more than y's
    // AND
    // x outTimeshould be less than y's
    if(inTime[x]>inTime[y] and outTime[x]<outTime[y]) 
        return true;
    return false;
}


int32_t main(){

	ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	vector<int> inTime(n+1);
	vector<int> outTime(n+1);
	int timer = 0;
    dfs(1,0,adj,inTime,outTime,timer);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int type,x,y;
        cin>>type>>x>>y;
        if(type==0){
            if(check(y,x,inTime,outTime))
                cout<<"YES\n";
            else 
                cout<<"NO\n";
        }
        else if(type==1){
            if(check(x,y,inTime,outTime))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        
    }
    return 0;
}
    




