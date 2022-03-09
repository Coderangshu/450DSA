// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            auto itr = mp.find(arr[i]);
            if(itr!=mp.end()) itr->second += 1;
            else mp[arr[i]] = 1;
        }
        static int ans[2];
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()) ans[1] = i;
            else if(mp.at(i)==2) ans[0] = i;
        }
        return ans;
    }
};

// Using bitmasking
class Solution1{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int a = 0, b = 0, xr = arr[0];
        for(int i=1;i<n;i++) xr ^= arr[i];
        for(int i=1;i<=n;i++) xr ^= i;
        int lstb = xr&(-xr);
        for(int i=0;i<n;i++){
            if(lstb&arr[i]) a ^= arr[i];
            else b ^= arr[i];
        }
        for(int i=1;i<=n;i++){
            if(lstb&i) a ^= i;
            else b ^= i;
        }
        static int ans[2];
        bool found = false;
        for(int i=0;i<n;i++) if(arr[i]==a){
            found = true;
            break;
        }
        if(found) ans[0] = a, ans[1] = b;
        else ans[1] = a, ans[0] = b;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";

        Solution1 ob1;
        auto ans1 = ob1.findTwoElement(a, n);
        cout << ans1[0] << " " << ans1[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
