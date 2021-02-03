// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends





//User function Template for C++

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    // We are creating a map by sorting the letters of each string
    // and making that as the key of the map thus saving the same
    // anagrams under the same key. The sorting takes KLogK time 
    // complexity, where K is the length of the longest string.
    // We do the sorting for all the n element in the vector thus
    // total time complexity is O(nKlogK), we can decrease this to
    // O(nK) by not sorting the strings but creating a has value
    // out of it and using that as the key.
    int n = string_list.size();
    unordered_map <string,vector<string>> mp;
    for(int i=0;i<n;i++){
        string s = string_list[i];
        string ss = s;
        sort(ss.begin(),ss.end());
        mp[ss].push_back(s);
    }
    vector<vector<string>> ans;
    for(auto e:mp) ans.push_back(e.second);
    return ans;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends
