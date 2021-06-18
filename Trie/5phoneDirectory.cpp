// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:


    // Method: trie is created and the contacts stored
    // for each query string we make it the suffix and search
    // for it in the trie if found then we traverse through this
    // strings neighbours using DFS this way we get all the strings
    // that consist of the given query string as there prefixes




    // trie node
    struct trieNode{
    	map<char,struct trieNode*> mp;
    	bool endOfWord = false;
    };
    
    // insert to trie
    void insert(struct trieNode* root, string word){
    	struct trieNode* current = root;
    	for(int i=0;i<word.length();i++){
    	    char key = word[i];
    		if(current->mp.find(key)==current->mp.end())
    			current->mp[key] = new trieNode;
    		current = current->mp[key];
    	}
    	current->endOfWord = true;
    }
    
    // search in trie
    pair<bool,struct trieNode*> getAddressOfQuery(struct trieNode* root, string word){
       struct trieNode* current = root;
       for(int i=0;i<word.length();i++){
    	   int key = word[i];
    	   if(current->mp.find(key)==current->mp.end()) return {false,NULL};
    	   current = current->mp[key];
       }
       return make_pair(true,current);
    }
    
    // For each query string obtained we get upto the address of the query string(if present)
    // using the above getAddressOfQuery function
    // Then in the below function we traverse through all the neighbours of this query string
    // DFSely this gives all the possible strings using this quesry string prefix
    void getStringsWithCurrentSuffix(struct trieNode* root, string prefix, vector<string> &ans){
        if(root->endOfWord) ans.push_back(prefix);
        for(auto e:root->mp){
            // letter is added to the prefix
            prefix.push_back(e.first);
            // new prefix sent for DFS
            getStringsWithCurrentSuffix(e.second,prefix,ans);
            // letter added is removed(backtracked)
            // so that for the next iteration of the next neighbour
            // the prefix remains the same
            prefix.pop_back();
        }
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        // trie created and contacts inserted
        struct trieNode* root = new trieNode;
        for(int i=0;i<n;i++) insert(root,contact[i]);
        
        // ans vector of vector of string
        vector<vector<string>> ans;
        
        // auto suggestion after each letter of query string s given
        for(int i=1;i<=s.length();i++){
            string q = s.substr(0,i);
            vector<string> vecOfWordsWithCurrentSuffix;
            auto pr = getAddressOfQuery(root,q);
            bool booltf = pr.first;
            auto address = pr.second;
            if(booltf)
                getStringsWithCurrentSuffix(address,q,vecOfWordsWithCurrentSuffix);
            else vecOfWordsWithCurrentSuffix.push_back("0");
            ans.push_back(vecOfWordsWithCurrentSuffix);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
