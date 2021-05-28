// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    // Using preorder and inorder we can get the tree as follows:
    // Let preorder be {0 1 3 4 2 5} and inorder be {3 1 4 0 5 2}
    // We know preorder has root in the first location thus we get
    // the root and from inorder we get the elements in left and right
    // Tree thus formed now is  0
    //                        /   \
    //                     1 3 4  2 5
    // Now we do the same recursively for both left and right to get the
    // complete tree
    
    Node* buildTreeRecursive(int in[], int pre[], int start, int end, int &preInd, unordered_map<int,int> &mp){
        // start and end denotes the begining and end of the preorder array
        if(start>end) return NULL;
        
        // Take the preInd element from pre[] and for a node
        // preInd is acting as a counter parsing each element
        // in pre[]
        int num = pre[preInd++];
        Node * node = new Node(num);
        
        // If start=end, i.e. it is the leaf node
        if(start==end) return node;
        
        // We get the index of the current number in the in[]
        int inInd = mp[num];
        
        // We call recursively for left node then for right node 
        node->left = buildTreeRecursive(in,pre,start,inInd-1,preInd,mp);
        node->right = buildTreeRecursive(in,pre,inInd+1,end,preInd,mp);
        return node;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        // Map to store the index of each element in the
        // inorder list with key being the element and value
        // being the index of it
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[in[i]] = i;
        int preInd = 0;             // stores the index of preorder list to be parsed
        return buildTreeRecursive(in,pre,0,n-1,preInd,mp);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
