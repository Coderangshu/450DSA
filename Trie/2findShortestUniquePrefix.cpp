#include<bits/stdc++.h>
using namespace std;

// trie structure
struct trieNode{
	map<char,trieNode*> mp;
	// here we use a frequency data to keep
	// track of the number of times the node
	// is visited, here we do not maintain the
	// endOfWord bool data as we do not need
	// information about the word stored
	int frequency = 0;
};

void insert(trieNode *root, string word){
	trieNode * currentNode = root;

	//traversing through word's each letter
	for(auto letter:word){
		// if letter not present then add a node of it and increment
		// frequency
		if(currentNode->mp.find(letter)==currentNode->mp.end()){
			currentNode->mp[letter] = new trieNode;
			currentNode->frequency++;
		}
		// if present then increase the frequency of the current
		// node as it has been visited once again due to the presence
		// of the child letter again
		else currentNode->frequency++;
		
		// move to the letter's node
		currentNode = currentNode->mp[letter];
	}
}

void findPrefixesUtil(trieNode *root, string prefix){
	// base case
	// if root is empty
	if(root==NULL) return;
	// if root's map's length is 1 or 0 means this is 
    // map which contains the first uncommon letter or
    // is the end of the word thus print the prefix
	else if(root->mp.size()==1 or root->mp.empty()){
		cout<<prefix<<endl;
		return;
	}
	// else we add the current letter and go to next node
	else{
		for(auto e:root->mp){
			prefix.push_back(e.first);
			findPrefixesUtil(e.second,prefix);
			// popping the last letter added(Backtrack)
			prefix.pop_back();
		}
	}
}

// wrapper function to get the unique prefixes
void findPrefixes(vector<string> words, int n){
	// create and insert all words into the trie
	struct trieNode* root = new trieNode;
	for(auto word:words) insert(root,word);

	string prefix;
	findPrefixesUtil(root,prefix);
}

// Driver function.
int main(){
    vector<string> arr = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr)/sizeof(arr[0]);
    findPrefixes(arr, n);

    return 0;
}


// The trie of the above arr is as follows :
// The number at each level's beginning denotes the frequency of 
// that node followed by the letters present in its map
// N means the map of that letter is empty
// 
// 
// 
//                      3 d z
//                       /   \ 
//                      /     \ 
//                     /       \ 
//                  3 o u       1 e
//                   /   \       |
//                  /     \     1 b
//             2 g v      1 c    |
//              /   \      |    1 r 
//             /     \    1 k    |
//             N    1 e    |    1 a
//                   |     N     |
//                   N           N
//
//
//
