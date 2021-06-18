// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/


// Method: Trie inserts single copy of evey instance thus we insert
// every row and if while inserting we found that the row has been
// inserted previously then we return false meaning it is a duplicate
// else we return true and the row is added to the vector of vector of
// int



// trie node
struct trieNode{
	unordered_map<int,struct trieNode*> mp;
	bool endOfRow = false;
};

bool insert(struct trieNode* root, vector<int> row){
	struct trieNode* current = root;
	for(int i=0;i<row.size();i++){
		int key = row[i];
		// if key not in map then create node and store
		// its address in the map with the char being
		// the key
		if(current->mp.find(key)==current->mp.end())
			current->mp[key] = new trieNode;
		// go to the next letter's trie node
		current = current->mp[key];
	}
	// if last node (leaf) is marked means row previously inserted
	// return false else return true as row inserted for first time
	if(!(current->endOfRow)) return current->endOfRow = true;
	else return false;
}

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    //Your code here
    vector<vector<int>> ans;
    struct trieNode* root = new trieNode;
    for(int i=0;i<row;i++){
        vector<int> currentRow;
        for(int j=0;j<col;j++) currentRow.push_back(M[i][j]);
        if(insert(root,currentRow)) ans.push_back(currentRow);
    }
    return ans;
}
