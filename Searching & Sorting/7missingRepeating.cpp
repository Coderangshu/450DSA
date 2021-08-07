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
    }
    return 0;
}  // } Driver Code Ends
