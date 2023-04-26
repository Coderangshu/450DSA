#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(vector<int> adj[], int u, int parent, int vis[], vector<int> &path, unordered_set<string> &allCycles){
	// visited completely
	if(vis[u]==2) return;
	// visited previously in this path
	// implies this path contains a cycle
	if(vis[u]==1){
		bool flag = false;
		vector<int> resPath;
		for(auto &e:path){
			if(e==u) flag = true;
			if(flag) resPath.push_back(e);
		}
		sort(resPath.begin(),resPath.end());
		string s  = "";
		for(auto &e:resPath) s += to_string(e)+" ";
		allCycles.insert(s);
		return;
	}
	vis[u] = 1;
	path.push_back(u);
	for(auto &v:adj[u]){
		if(v!=parent){
			dfs(adj,v,u,vis,path,allCycles);
		}
	}
	path.pop_back();
	vis[u] = 0;
	return;
}

int main(){
	int n = 8;
	vector<int> adj[n];

	addEdge(adj, 0, 1);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 0);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 4);
	addEdge(adj, 4, 5);
	addEdge(adj, 6, 7);

	for(int i=0;i<n;i++){
		cout<<i<<": ";
		for(auto &e:adj[i]) cout<<e<<" ";
		cout<<endl;
	}

	int vis[n] = {0};
	unordered_set<string> allCycles;
	vector<int> path;

	for(int i=0;i<n;i++){
		dfs(adj,i,-1,vis,path,allCycles);
		vis[i] = 2;
	}

	for(auto &path:allCycles) cout<<path<<endl;
	cout<<"Total number of cycles : "<<allCycles.size()<<endl;

	return 0;
}
