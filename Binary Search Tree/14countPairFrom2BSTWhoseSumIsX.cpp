// { Driver Code Starts
// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/


void storeBSTNodes(Node* root, vector<int> &nodes){
	// Base case
	if (root==NULL) return;

	// Store nodes in Inorder (which is sorted
	// order for BST)
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root->data);
	storeBSTNodes(root->right, nodes);
}


// You are required to complete this function
int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    vector<int> in1, in2;
    storeBSTNodes(root1,in1);
    storeBSTNodes(root2,in2);
    int count = 0;
    for(int i=0;i<in1.size();i++){
        for(int j=0;j<in2.size();j++){
            if(in1[i]+in2[j]==x) count++;
            if(in1[i]+in2[j]>x) break;
        }
    }
    return count;
}
