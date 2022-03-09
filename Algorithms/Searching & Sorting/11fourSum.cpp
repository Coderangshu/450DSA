#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int reqSum = k-arr[i]-arr[j];
                int l = j+1, r = n-1;
                while(l<r){
                    int sum = arr[l]+arr[r];
                    if(sum==reqSum){
                        ans.push_back({arr[i],arr[j],arr[l],arr[r]});
                        int la = arr[l], ra = arr[r];
                        while(arr[l]==la) l++;
                        while(arr[r]==ra) r--;
                    }
                    else if(sum>reqSum) r--;
                    else l++;
                }
            }
        }
        return ans;
    }
};

int main(){
    int k = 23;
    vector<int> v = {10,2,3,4,5,7,8};
    Solution obj = Solution();
    vector<vector<int>> ans = obj.fourSum(v,k);
    for(auto &e:ans){
        for(auto &f:e){
            cout<<f<<" ";
        }
        cout<<endl;
    }
    return 0;
}