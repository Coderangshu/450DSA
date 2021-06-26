        

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // We store the dictionary in a trie as insertion and
    // searching in a trie occurs in linear time, can also
    // use unordered_map, but trie is better space efficient
    // than the map

    // struct of trie
    struct trieNode{
        unordered_map<char,trieNode*> mp;
        bool eow = false;
    };
    
    // insert word into trie
    void insert(struct trieNode* root, string word){
        struct trieNode* current = root;
        for(auto letter:word){
            if(current->mp.find(letter)==current->mp.end()){
                struct trieNode* next = new trieNode;
                current->mp[letter] = next;
            }
            current = current->mp[letter];
        }
        current->eow = true;
    }
    
    // search trie
    bool search(struct trieNode* root, string word){
        struct trieNode* current = root;
        for(auto letter:word){
            if(current->mp.find(letter)==current->mp.end()) return false;
            current = current->mp[letter];
        }
        return (current->eow);
    }
    
    // Looping and breaking the given word into substring if substring present
    // in trie than add to current sentence(prefix) and then send this prefix and
    // the other substring to be checked, then after processing of that part is
    // over remove the substring from the current sentence(backtrack) and go 
    // on with the loop
    void wordBreakUtil(struct trieNode* root, string s, vector<string> prefix, vector<string> &ans){
        int n = s.length();
        // base case
        // if the string arrived is of length either
        // 1 or 0 than we add the word to the current
        // sentence and add this string to the result
        // and terminate the recursion
        if(n<=1){
            prefix.push_back(s);
            string fstr = "";
            for(auto word:prefix) 
                if(word!="") fstr += word+" ";
            // removing the extra space added in the fstr
            fstr.pop_back();
            // adding the sentence to the result
            ans.push_back(fstr);
            return;
        }
        for(int i=1;i<=n;i++){
            // create each substring
            string sstr = s.substr(0,i);
            // if substring present in trie(dictionary)
            if(search(root,sstr)){
                // substring added to prefix
                prefix.push_back(sstr);
                // sent for next word now the string of 
                // concern being the left over substring
                wordBreakUtil(root,s.substr(i,n-i),prefix,ans);
                // backtrack
                prefix.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        
        // create the trie from given dictionary
        struct trieNode* root = new trieNode;
        for(auto e:dict) insert(root,e);
        
        vector<string> prefix,ans;
        wordBreakUtil(root,s,prefix,ans);
        return ans; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
