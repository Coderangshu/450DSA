#include<bits/stdc++.h>
#define int long long int
using namespace std;


// here we observe that descending order will give the max amplification
// as the power is higher on the later stages that increases the # greatly
// but theres some exceptions in there
// (1) if theres 1 then that should be exponentiated at the last, as if in between
//     or in the begining the complete number gets converted to 1 power something that
//     always gives 1
// (2) if theres only 2 and 3 other than 1 then for this case 3^2 > 2^3 thus only in this
//     case we need to print it in the ascending order
void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        int countOnes = 0;
        for(int i=0;i<n;i++){
            int e;
            cin>>e;
            if(e==1) countOnes++;
            v[i] = e;
        }
        
        sort(v.begin(),v.end(),greater<int>());

        for(int i=0;i<countOnes;i++) cout<<"1 ";
        if(n-countOnes==2 and v[0]==3 and v[1]==2) cout<<"2 3"<<endl;
        else{
            for(int i=0;i<n-countOnes;i++) cout<<v[i]<<" ";
            cout<<endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}