#include<bits/stdc++.h>
using namespace std;



// Trie is a n-ary tree with the address of each of its
// child node being stored in map or array (as per requirement)
// it also contains a bool to keep track of the end of each word
// in the structure wherever it is true means it is the end of
// a particular word inside the trie.
// Insert and Search time in trie is O(n) where n is length of word
// Space complexity is O(char_size * word_length * number_of_words) 




// trie node
struct trieNode{
	unordered_map<char,struct trieNode*> mp;
	bool endOfWord = false;
};

void insert(struct trieNode* root, string word){
	struct trieNode* current = root;
	for(int i=0;i<word.length();i++){
		int key = word[i]; 
		// if key not in map then create node and store
		// its address in the map with the char being
		// the key
		if(current->mp.find(key)==current->mp.end())
			current->mp[key] = new trieNode;
		// go to the next letter's trie node
		current = current->mp[key];
	}
	// mark last node as leaf
	current->endOfWord = true;
}

bool search(struct trieNode* root, string word){
   struct trieNode* current = root;
   for(int i=0;i<word.length();i++){
	   int key = word[i];
	   // if key not in trie return false
	   if(current->mp.find(key)==current->mp.end()) return false;
	   // else go to the trieNode of the current character
	   current = current->mp[key];
   }
   // if the word's last letter's node's endOfWord is true means
   // this word exists else it isn't in the trie
   return (current->endOfWord);
}

trieNode* remove(trieNode* root, string word, int index = 0){
	// if trie is empty
	if(!root){
        cout<<"Empty trie\n";
        return NULL;
    }

	// if last character of word is being processed
	else if(index==word.length()){
		// this isn't the end of a word anymore
		// thus we need to mark its endOfWord as false
		root->endOfWord = false;

		// also if the map is empty means that no further
		// words are present that would have been using this
		// suffix thus we delete this node
		if(root->mp.empty()){
			delete root;
			root = NULL;
		}
		return root;
	}

	// if not last letter we recurse to the last letter
	else{
		char letter = word[index];
		// we mark the child nodes address of current with
		// what is returned after deleting the next letters
		// recursively
		root->mp[letter] = remove(root->mp[letter],word,index+1);

		// if mp[letter] becomes null then we remove leter from map
		if(root->mp[letter]==NULL) root->mp.erase(letter);

		// after processing from last to this letter is this letter's
		// map is empty this means that no further words use the suffix
		// uptil now thus delete this letter's node
        // also if its endOfWord is false means this isn't
		// the end of any word thus we check both condition
		// to delete node
		if(root->mp.empty() and root->endOfWord==false){
			delete root;
			root = NULL;
		}
		return root;
	}
}

void printSearchResult(struct trieNode* root, string word){
    cout<<word<<"     \t\t-> ";
	search(root,word)?cout<<"present\n":cout<<"not present\n";
}

int main(){
	string words[] = {"the","a","there","answer","any","by","bye","their","hero","heroplane"};
    int n = sizeof(words)/sizeof(words[0]);
	
	struct trieNode* root = new trieNode;

	// Construct tree
	for(int i=0;i<n;i++) insert(root,words[i]);

	// print the result after searching a word
    
    printSearchResult(root,"a");
    printSearchResult(root,"the");
    printSearchResult(root,"these");
    printSearchResult(root,"them");
    printSearchResult(root,"bye");
    printSearchResult(root,"hero");
    printSearchResult(root,"heroplane");
    
    // deleting 'heroplane'
	remove(root,"heroplane");
	cout<<"\nAfter removing 'heroplane'\n";
    
	printSearchResult(root,"a");
    printSearchResult(root,"the");
    printSearchResult(root,"these");
    printSearchResult(root,"them");
    printSearchResult(root,"bye");
    printSearchResult(root,"hero");
    printSearchResult(root,"heroplane");

	return 0;
}
