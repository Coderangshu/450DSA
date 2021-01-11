#include <bits/stdc++.h>
using namespace std;

class Solution{
    public : int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int small = arr[0]+k;
        int big = arr[n-1]-k;
        if (small>big) swap(small,big);
        for(int i=1;i<n-1;i++){
            int diff = arr[i]-k;
            int add = arr[i]+k;
            if(add<=big || diff>=small) continue;
            if(add-small<=big-diff) big = add;
            else small = diff;
        }
        return big - small;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
