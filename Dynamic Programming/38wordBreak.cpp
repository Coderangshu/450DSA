        // }

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

struct trieNode{
    unordered_map<char,struct trieNode*> mp;
    bool endOfWord = false;
};

void insert(struct trieNode *root, string word){
    struct trieNode *current = root;
    for(int i=0;i<word.length();i++){
        char letter = word[i];
        if(current->mp.find(letter)==current->mp.end())
            current->mp[letter] = new trieNode;
        current = current->mp[letter];
    }
    current->endOfWord = true;
}

bool search(struct trieNode *root, string word){
    struct trieNode *current = root;
    for(int i=0;i<word.length();i++){
        char letter = word[i];
        if(current->mp.find(letter)==current->mp.end())
            return false;
        current = current->mp[letter];
    }
    return (current->endOfWord);
}

bool wordBreakUtil(struct trieNode *root, string jword){
    int n = jword.length();
    if(n==0) return true;
    for(int i=1;i<=n;i++){
        string word = jword.substr(0,i);
        if(search(root,word) and wordBreakUtil(root,jword.substr(i,n-i)))
            return true;
    }
    return false;
}

int wordBreak(string A, vector<string> &B) {
    //code here
    // We can use the given vector of string to search for each
    // word every time this would give us a search time complexity
    // of O(n) every time. To reduce this we store the vector of
    // string in a trie dictionary
    
    // Creating the trie dictionary
    struct trieNode *root = new trieNode;
    for(int i=0;i<B.size();i++) insert(root,B[i]);
    
    return wordBreakUtil(root,A);
}
