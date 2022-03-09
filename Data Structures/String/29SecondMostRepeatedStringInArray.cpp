// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Using unordered_map
// TC : O(n)
// SC : O(n)
class Solution
{
  public:
    string secFrequent (string arr[], int n){
        unordered_map<string, int> occ; 
        for (int i=0;i<n;i++) occ[arr[i]]++;
        pair<string,int> largest("",INT_MIN), secondLargest("",INT_MIN);
        for(auto e:occ){
            if(e.second>=largest.second) {
                secondLargest.first = largest.first;
                secondLargest.second = largest.second;
                largest.first = e.first;
                largest.second = e.second;
            }
            else if(e.second>secondLargest.second){
                secondLargest.first = e.first;
                secondLargest.second = e.second;
            }
        }
        return secondLargest.first;
    }
};


// Using Boyer Moore's Algorithm
// TC : O(n)
// SC : O(1)
class Solution1{
public:
    string secFrequent(string arr[], int n){
        string f,s;
        int fcnt = 0, scnt = 0;
        for(int i=0;i<n;i++){
            if(fcnt==0) f = arr[i], fcnt++;
            else if(arr[i]==f) fcnt++;
            else fcnt--;
        }
        for(int i=0;i<n;i++){
            if(arr[i]==f) continue;
            if(scnt==0) s = arr[i], scnt++;
            else if(arr[i]==s) scnt++;
            else scnt--;
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;

        Solution1 ob1;
        cout << ob1.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
