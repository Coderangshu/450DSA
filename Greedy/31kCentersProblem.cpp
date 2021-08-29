#include<bits/stdc++.h>
#define int long long int
using namespace std;

void selectKcities(vector<vector<int>> &distances, int k){
    int n = distances.size();
    // to store the k centers
    vector<int> centers;

    // to store the min distance of each city to there nearest center
    // initially all cities are at infinite distance from centers
    vector<int> dist(n,INT_MAX);
    
    // taking 0 as the first arbitary center
    int center = 0;
    centers.push_back(center);

    // getting min distance of all cities from the current center
    // doing so for all the k centers
    for(int i=1;i<k;i++){
        for(int j=0;j<n;j++) dist[j] = min(dist[j],distances[center][j]);
        // getting the city that is farthest from current
        // center and making it as the next center
        center = max_element(dist.begin(),dist.end())-dist.begin();
        centers.push_back(center);
    }
    for(auto e:centers) cout<<e<<" ";
    cout<<endl;
}

void solve(){
    vector<vector<int>> distances = { { 0, 4,  8,  5 },
                                      { 4, 0,  10, 7 },
                                      { 8, 10, 0,  9 },
                                      { 5, 7,  9,  0 } };
    int k = 2;
    selectKcities(distances, k);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}