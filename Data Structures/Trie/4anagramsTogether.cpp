// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends
//User function Template for C++

// As insertion and search time in trie is O(k) where k is length
// of longest word, thus total time taken is O(kklogk) where klogk
// is for sorting the string

// Method: sort each word insert into trie and at the leaf node
// we have a vector which contains the original words thus all the
// anagrams are stored in the same vector, lastly we need to put
// this vectors into a vector of vector and return.

// trie node
struct trieNode{
	unordered_map<char,struct trieNode*> mp;
	// vector to store the original strings
	// Note: this vector will be empty for all nodes
	// except for the leaf nodes(i.e. where endOfWord is true)
	vector<string> vecOfAnagramsTogether;
	bool endOfWord = false;
};

void insert(struct trieNode* root, string word, string sortedWord){
	struct trieNode* current = root;
	for(int i=0;i<sortedWord.length();i++){
		int key = sortedWord[i]; 
		// if key not in map then create node and store
		// its address in the map with the char being
		// the key
		if(current->mp.find(key)==current->mp.end())
			current->mp[key] = new trieNode;
		// go to the next letter's trie node
		current = current->mp[key];
	}
	// mark last node as leaf and add original word to vector
	current->endOfWord = true;
	current->vecOfAnagramsTogether.push_back(word);
}

vector<vector<string>> getGroupOfAnagramsFromTrie(struct trieNode* root, vector<vector<string>> &ans){
    if(!root) return ans;
    if(root->endOfWord){
        ans.push_back(root->vecOfAnagramsTogether);
    }
    for(auto e:root->mp){
        getGroupOfAnagramsFromTrie(e.second,ans);
    }
    return ans;
}

vector<vector<string>> Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    struct trieNode* root = new trieNode;
    
    int n = string_list.size();
    for(int i=0;i<n;i++){
        string s = string_list[i];
        string ss = s;
        sort(ss.begin(),ss.end());
        insert(root,s,ss);
    }
    vector<vector<string>> ans;
    getGroupOfAnagramsFromTrie(root,ans);
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
