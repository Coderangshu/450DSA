#include<bits/stdc++.h>
using namespace std;

// trie node
struct trieNode{
	unordered_map<char,struct trieNode*> mp;
	bool endOfWord = false;
};

void insert(struct trieNode* root, string word){
	struct trieNode* current = root;
	for(int i=0;i<word.length();i++){
		int key = word[i];
		if(current->mp.find(key)==current->mp.end())
			current->mp[key] = new trieNode;
		current = current->mp[key];
	}
	current->endOfWord = true;
}

bool search(struct trieNode* root, string word){
   struct trieNode* current = root;
   for(int i=0;i<word.length();i++){
	   int key = word[i];
	   if(current->mp.find(key)==current->mp.end()) return false;
	   current = current->mp[key];
   }
   return (current->endOfWord);
}

// returns true if string can be segmented into
// space separated words, otherwise returns false

map<string,bool> memo;

bool wordBreak(string str, int length, trieNode *root){
    // Base case
    if(length==0) return true;
    
    // check if present in memo
    if(memo.find(str.substr(0,length))!=memo.end()) return memo[str.substr(0,length)];
    
    // Try all prefixes of lengths from 1 to size
    for (int i=1; i<=length; i++){
        // The parameter for search is str.substr(0, i)
        // str.substr(0, i) which is prefix (of input
        // string) of length 'i'. We first check whether
        // current prefix is in dictionary. Then we
        // recursively check for remaining string
        // str.substr(i, size-i) which is suffix of
        // length size-i
        if (search(root, str.substr(0, i)) and wordBreak(str.substr(i, length-i),length-i,root))
            return memo[str.substr(0,length)] = true;
    }
    // reaches here if not found any suitable string 
    return memo[str.substr(0,length)] = false;
}

int main()
{
    string dictionary[] = {"mobile","samsung","sam","sung","ma\n","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    struct trieNode *root = new trieNode;
  
    // Construct trie dictionary
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);
  
    wordBreak("ilikesamsung",12,root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii",8,root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("",0,root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii",18,root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango",15,root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok",16,root)? cout <<"Yes\n": cout << "No\n";
    
    return 0;
}
