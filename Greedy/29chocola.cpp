#include<bits/stdc++.h>
#define int long long int
using namespace std;

void solve(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<int> row,col;
        for(int i=0;i<m-1;i++){
            int e;
            cin>>e;
            row.push_back(e);
        }
        for(int i=0;i<n-1;i++){
            int e;
            cin>>e;
            col.push_back(e);
        }

        sort(row.begin(),row.end(),greater<int>());
        sort(col.begin(),col.end(),greater<int>());

        int i = 0, j = 0;
        int ans = 0;
        int horPieces = 1, vertPieces = 1;
        while(i<m-1 and j<n-1){
            if(row[i]>=col[j]){
                ans += vertPieces*row[i];
                horPieces++;
                i++;
            }
            else{
                ans += horPieces*col[j];
                vertPieces++;
                j++;
            }
        }
        while(i<m-1){
            ans += vertPieces*row[i];
            i++;
        }
        while(j<n-1){
            ans += horPieces*col[j];
            j++;
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