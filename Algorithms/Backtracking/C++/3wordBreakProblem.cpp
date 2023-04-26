#include<bits/stdc++.h>
using namespace std;


class Solution{
private:
    void recursion(string &s, unordered_set<string> &d,
                    string sp, int ind,vector<string> &ans){
        int n = s.length();
        if(ind==n) ans.push_back(sp.substr(1));
        else{
            string word = "";
            for(int i=ind;i<n;i++){
                word += s[i];
                if(d.count(word)) recursion(s,d,sp+" "+word,i+1,ans);
            }
        }
        return;
    }
public:
    vector<string> wordBreak(vector<string>& dict, string s)
    {
        // code here
        unordered_set<string> d(dict.begin(),dict.end());
        vector<string> ans;
        recursion(s,d,"",0,ans);
        return ans;
    }
};

int main(){
    vector<string> v{"cat","cats","sand","and","dog","dogs","sledge","ledge"};
    string s = "catsanddogsledge";
    Solution ob = Solution();
    auto ans = ob.wordBreak(v,s);
    for(auto &e:ans) cout<<e<<endl;
    return 0;
}