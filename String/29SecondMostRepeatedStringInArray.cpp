// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
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
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
