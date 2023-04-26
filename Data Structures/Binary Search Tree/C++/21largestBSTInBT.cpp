// C++ program to find largest BST in a
// Binary Tree.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

/* Helper function that allocates a new
node with the given data and NULL left
and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;

	return(node);
}

// Here we do a bottom up approach as the bottom subtrees
// will provide the information for a node above them
// info retrived can be used to decide if the tree with
// the current node as root is a BST or not.
// The info transformed from each node are:
//              max of subtree
//              min of subtree
//              size of largest BST till that node

// Information to be returned by every
// node in bottom up traversal.
struct Info
{
	int max; // Max value in subtree
	int min; // Min value in subtree
	int sz; // Size of largest BST which is subtree of current node
	Info(int x, int n, int s){
		max = x;
		min = n;
		sz = s;
	}
};

// Returns Information about subtree. The
// Information also includes size of largest
// subtree which is a BST.
Info largestBSTBT(Node* root)
{
	// Base cases : When tree is empty
	if (root == NULL) return Info(INT_MIN,INT_MAX,0);

	// Recur for left subtree and right subtrees
	Info l = largestBSTBT(root->left);
	Info r = largestBSTBT(root->right);

	// Check if root is maintains BST property
	if(l.max<root->data and root->data<r.min)
		return Info(max(root->data,r.max),min(root->data,l.min),1+l.sz+r.sz);

	// If not maintaining then send the max size of valid BST obtained till now
	// and return INT_MAX for max and INT_MIN for min so that none of the above
	// parent can become a valid BST
	return Info(INT_MAX,INT_MIN,max(l.sz,r.sz));
}

/* Driver program to test above functions*/
int main()
{
	/* Let us construct the following Tree
		60
	   / \
	  65 70
	 /
	50 
	*/

	struct Node *root = newNode(60);
	root->left = newNode(65);
	root->right = newNode(70);
	root->left->left = newNode(50);
	printf(" Size of the largest BST is %d\n",
		largestBSTBT(root).sz);
	return 0;
}

