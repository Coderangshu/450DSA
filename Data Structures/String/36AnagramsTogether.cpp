// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
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
    // TC : O(n*nlogn) 
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






// Method 2:
// Using better hash map (T(n) = O(n*26)) 

// function to get the hash key for each string
string getHash(string s){
        vector<int> arr(26,0);
        for(auto c:s){
            int e = c-'a';
            arr[e]++;
        }
        string ans = "";
        for(auto e:arr) ans += to_string(e)+" ";
        return ans;
    }

vector<vector<string>> Anagrams(vector<string>& string_list) 
{
    // creating hashmap with the hash key being the frequency
    // string representation of vector of all 26 chars with space
    unordered_map<string,vector<string>> um;
        vector<vector<string>> ans;
        for(auto e:strs){
            string hash = getHash(e);
            um[hash].push_back(e);
        }
        for(auto [_,vecs]:um) ans.push_back(vecs);
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
