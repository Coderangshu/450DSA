/* C++ program to calculate Kth ancestor of given node */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// temporary node to keep track of Node returned
// from previous recursive call during backtrack
Node* temp = NULL;

// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node , int &k, Node* &ans)
{
	// Base case
	if (!root) return NULL;
	
    // If root's data is node then if k>0 k-- and
    // return root
    // if not then call child of root left then right
    // first left is processed, the left node is also
    // stored in temp and as temp is inside if thus the 
    // if checks if temp isn't NULL then it goes inside
    // if else if NULL then the right child is processed
    // if root->left's data == node then go inside and
    // thus goes on
    // Note: temp is a recursive stack here storing the
    // the node before processing it
	if (root->data == node or
	(temp = kthAncestorDFS(root->left,node,k,ans)) or
	(temp = kthAncestorDFS(root->right,node,k,ans))){
		if (k > 0) k--;
		
		else if (k == 0){
			// save node in ans
			ans = root;
            
			// return NULL to stop further backtracking
			return NULL;
		}
		// return current node to previous call
        return root;
	}
	// this point will only be reached when the node isn't
	// present in tree, as all the statements inside the
	// above if condition would be exhausted as none are
	// satisfied
	return NULL;
}

// same as above
Node* kthAncestorDFS1(Node *root, int node , int &k, Node* &ans){
	if(!root) return nullptr;
	if(root->data == node or kthAncestorDFS1(root->left,node,k,ans) or kthAncestorDFS1(root->right,node,k,ans)){
		if(k>0) k--;
		else{
			ans = root;
			return nullptr;
		}
		return root;
	}
}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	int k = 2;
	int node = 5;
    Node *ans = NULL;
	// get kth ancestor of given node
    // parent will store NULL if ans found
    // also NULL is returned to break the backtracking
    // process
    // if node not found even then parent will
    // return NULL
    // parent will return a node only if k is larger
    // than ancestors available
	// Node* parent = kthAncestorDFS(root,node,k,ans);
	Node* parent = kthAncestorDFS1(root,node,k,ans);
	
	// check if parent is not NULL, it means
	// there is no Kth ancestor of the node
	if (ans) cout<<ans->data<<endl;
	else cout<<"Doesn't exist"<<endl;
	return 0;
}

