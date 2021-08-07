// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // your code here
        unordered_map<int,int> mp;
        for(int i=0;i<size;i++){
            auto itr = mp.find(a[i]);
            if(itr!=mp.end()) itr->second += 1;
            else mp[a[i]] = 1;
        }
        int change = 0,maxVal = INT_MIN;
        int ans;
        for(auto itr:mp){
            if(itr.second>maxVal and itr.second>size/2){
                maxVal = itr.second;
                ans = itr.first;
                change++;
            }
        }
        if(maxVal==INT_MIN) return -1; 
        return ans;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
