#include<bits/stdc++.h>
#define int long long int
using namespace std;

// code is self explanatory using the variable
// names as hint, easy to understand
void solve(){
    int tc, tn;
    cin>>tc;
    tn = 0;
    while(tn++!=tc){
        int n,k,b,t;
        cin>>n>>k>>b>>t;
        vector<int> x,v;
        for(int i=0;i<n;i++){
            int e;
            cin>>e;
            x.push_back(e);
        }
        for(int i=0;i<n;i++){
            int e;
            cin>>e;
            v.push_back(e);
        }

        int totSwaps = 0, cantReach = 0;
        for(int i=n-1;i>=0;i--){
            int distToTravel = b-x[i];
            int distCanTravel = v[i]*t;
            if(distToTravel>distCanTravel) cantReach++;
            else{
                k--;
                totSwaps += cantReach;
            }
            if(k<=0) break;
        }
        cout<<"Case #"<<tn<<": ";
        (k>0)?cout<<"IMPOSSIBLE":cout<<totSwaps;
        cout<<endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}