#include<bits/stdc++.h>
#define int long long int
using namespace std;

void solve(){
    int n;
    while(true){
        cin>>n;
        if(n==0) break;
        vector<pair<int,int>> buyer, seller;
        for(int i=0;i<n;i++){
            int e;
            cin>>e;
            if(e>0) buyer.push_back({e,i});
            else seller.push_back({-e,i});
        }
        int currentSeller = 0, currentBuyer = 0;
        int ans = 0;
        while(currentBuyer<buyer.size() and currentSeller<seller.size()){
            
            int toTransact = min(buyer[currentBuyer].first,seller[currentSeller].first);
            int distance = abs(buyer[currentBuyer].second-seller[currentSeller].second);
            
            buyer[currentBuyer].first -= toTransact;
            seller[currentSeller].first -= toTransact;
            ans += (toTransact*distance);
            
            // going to next buyer and seller if conditions satify
            if(buyer[currentBuyer].first==0) currentBuyer++;
            if(seller[currentSeller].first==0) currentSeller++;
        }
        cout<<ans<<endl;
    }
}

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
