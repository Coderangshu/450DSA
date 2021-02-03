// Reference : https://youtu.be/AXjmTQ8LEoI
#include <bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)	tolower(c)-(int)'a')

// TrieNode structure and initializer
struct TrieNode{
	struct TrieNode *children[26] = {NULL};
	bool isLeaf = false;
};

// Insert a new node in the trie
void TrieInsert(struct TrieNode *root,string key){
	// The maximum depth of the tree can be as long as
	// the length of the current word length
	int len = key.length();
	// We start crawling from the root node, wherever the
	// current character is found the crawler is taken to the
	// children of that node. If not present then create a new node.
	struct TrieNode *crawler = root;
	for(int level=0;level<len;level++){
		char lowercase = tolower(key[level]);
		int index = CHAR_TO_INDEX(lowercase);
		if(!crawler->children[index]) crawler->children[index] = new TrieNode;
		crawler = crawler->children[index];
	}
	// The last character's leaf is set to true, meaning that this
	// is the last node of a particular word.
	crawler->isLeaf = true;
}

void constructTrie(string ar[], int n, TrieNode *root){
	for(int i=0;i<n;i++) TrieInsert(root,ar[i]);
}

// The number of childrens for a particular node is calculated
int countChildren(struct TrieNode *node, int *index){
	int count = 0;
	// Traversing through the complete children array
	for(int i=0;i<26;i++) if(node->children[i]!=NULL){
		count++;
		*index = i;
	}
	return count;
}

// Traverse through the complete trie to find the largest prefix
string walkTrie(struct TrieNode *root){
	struct TrieNode *crawler = root;
	string longestPrefix = "";
	int index;
	// Until count of children for current node is 1 and also not the
	// last node of the trie, we go down the tree as these are the part
	// of the common ancestor.
	while(countChildren(crawler,&index)==1 and crawler->isLeaf==false){
		crawler = crawler->children[index];
		longestPrefix += 'a'+index;
	}
	return longestPrefix;
}

string commonPrefix(string arr[], int n){
	struct TrieNode *root = new TrieNode;
	constructTrie(arr,n,root);
	return walkTrie(root);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string strSet[n];
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			strSet[i] = s;
		}
		//for(int i=0;i<n;i++) cout<<strSet[i]<<endl;
		string ans = commonPrefix(strSet,n);
		if(ans.length()) cout<<"The longest common prefix is "<<ans<<endl; 
		else cout<<"There is no common prefix"<<endl;
	}
	return 0;
}
