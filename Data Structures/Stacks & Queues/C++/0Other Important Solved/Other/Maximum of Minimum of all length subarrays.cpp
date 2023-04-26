#include <bits/stdc++.h>
using namespace std;

// Brute force take all subarrays of all lengths
// calculate min for each then calculate the max of all
// TC : O(n^3)
// SC : O(1)
void printMaxOfMinBF(vector<int> &arr){
    int n = arr.size();
    int maxOfthisLength = INT_MIN;
    for(int len=1;len<=n;len++){
        int tans = INT_MAX;
        for(int i=0;i<=n-len;i++){
            for(int j=0;j<=len;j++) tans = min(tans,arr[i+j]);
        }
        maxOfthisLength = max(maxOfthisLength,tans);
        cout<<maxOfthisLength<<" ";
    }
    cout<<endl;
    return;
}

// Using nse and pse
// TC : O(n)
// SC : O(n)
void printMaxOfMin(vector<int> &arr){
    int n = arr.size();
    // calculating previous and next smallest for each element
    stack<int> stk;
    vector<int> pse(n),nse(n);
    for(int i=0;i<n;i++){
        while(!stk.empty() and arr[stk.top()]>=arr[i]) stk.pop();
        if(stk.empty()) pse[i] = -1;
        else pse[i] = stk.top();
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() and arr[stk.top()]>=arr[i]) stk.pop();
        if(stk.empty()) nse[i] = n;
        else nse[i] = stk.top();
        stk.push(i);
    }
    // the nse and pse gives us that arr[i] is the smallest in the subarray
    // between pse[i] and nse[i] (excluding the boundary)
    // thus arr[i] is smallest in subarray of length nse[i]-pse[i]-1
    vector<int> ans(n+1,INT_MIN);
    // storing the max of the minimums for each length found
    for(int i=0;i<n;i++){
        int len = nse[i]-pse[i]-1;
        ans[len] = max(ans[len],arr[i]);
    }
    // now some in ans are still INT_MIN as there aren't direct min element
    // for these lengths
    // Also for each length the max would be the max of elements found from 
    // length+1, length+2,.... to n
    // Using this above we update max of min all, starting from last
    for(int i=n-1;i>=0;i--) ans[i] = max(ans[i],ans[i+1]);
    for(int i=1;i<n+1;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return;
}

int main(){
    vector<int> arr = { 10, 20, 30, 50, 10, 70, 30 };
    printMaxOfMinBF(arr);
    printMaxOfMin(arr);
    return 0;
}