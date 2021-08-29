#include<bits/stdc++.h>
#define int long long int
using namespace std;

void solve(){
    string s;
    cin>>s;
    unordered_map<char,int> charFreq;
    for(auto e:s) charFreq[e]++;

    priority_queue<pair<char,int>,vector<pair<char,int>>> pq;
    for(auto e:charFreq) pq.push({e.second,e.first});

    string ans = "";
    while(!pq.empty()){
        pair<int,char> e = pq.top();
        char c1 = e.second;
        int f1 = e.first;
        ans += c1;
        pq.pop();
        char c2;
        int f2 = 0;
        if(!pq.empty()){
            e = pq.top();
            c2 = e.second;
            f2 = e.first;
            pq.pop();
            ans += c2;
        }
        if(f1-1>0) pq.push({f1-1,c1});
        if(f2-1>0) pq.push({f2-1,c2});
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}