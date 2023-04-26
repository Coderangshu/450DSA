// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node {
	int data;
	node* left;
	node* right;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};






// We got a naive method to print inorder but that takes O(n) space in recursion stack
// This method overcomes that with a little improvement of O(h) space

// Herein the prev stores the previous for a complete level than passing it to dummy to be
// printed, than prev is reset and the right subtree is traversed upto all the level
// this way the space complexity is reduced.





// Function to print flattened
// binary Tree
void print(node* parent)
{
	node* curr = parent;
	while (curr != NULL){
		cout << curr->data << " ";
        curr = curr->right;
    }
}

// Function to perform in-order traversal
// recursively
void inorder(node* curr, node*& prev)
{
	// Base case
	if (curr == NULL)
		return;
	inorder(curr->left, prev);
	prev->left = NULL;
	prev->right = curr;
	prev = curr;
	inorder(curr->right, prev);
}

// Function to flatten binary tree using
// level order traversal
node* flatten(node* parent)
{
	// Dummy node
	node* dummy = new node(-1);

	// Pointer to previous element
	node* prev = dummy;

	// Calling in-order traversal
	inorder(parent, prev);

	prev->left = NULL;
	prev->right = NULL;
	node* ret = dummy->right;

	// Delete dummy node
	delete dummy;
	return ret;
}

// Using inorder traversal only
class Solution{
	struct Node{
		int val;
		Node *left, *right;
		Node(int x){
			val = x;
			left = right = nullptr;
		}
	};

	Node* recursion(Node *root, Node *&last){
		if(!root) return nullptr;
		if(!root->left and !root->right ){
			last = root;
			return root;
		}
		Node *left = nullptr;
		if(root->left){
			left = recursion(root->left,last);
			last->right = root;
		}
		if(!root->right) last = root;
		else root->right = recursion(root->right,last);
		return (left)?left:root;
	}

	void inorder(Node *root){
		if(!root) return;
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}

	void printFlatten(Node*root){
		Node *cur = root;
		while(cur){
			cout<<cur->val<<" ";
			cur = cur->right;
		}
	}
public:
	void run(){
		Node *root = new Node(5);
		root->left = new Node(3);
		root->right = new Node(8);
		root->left->left = new Node(2);
		root->left->right = new Node(4);
		root->right->left = new Node(7);
		root->right->left->left = new Node(6);

		Node *root1 = new Node(8);
		root1->left = new Node(7);
		root1->left->left = new Node(6);
		root1->left->left->left = new Node(5);
		root1->left->left->left->left = new Node(4);
		root1->left->left->left->left->left = new Node(3);
		root1->left->left->left->left->left->left = new Node(2);
		root1->left->left->left->left->left->left->left = new Node(1);

		Node *root2 = new Node(1);
		root2->right = new Node(2);
		root2->right->right = new Node(3);
		root2->right->right->right = new Node(4);
		root2->right->right->right->right = new Node(5);
		root2->right->right->right->right->right = new Node(6);
		root2->right->right->right->right->right->right = new Node(7);
		root2->right->right->right->right->right->right->right = new Node(8);
		
		inorder(root);
		cout<<endl;
		Node *last = nullptr;
		root = recursion(root,last);
		printFlatten(root);

		cout<<endl;

		inorder(root1);
		cout<<endl;
		last = nullptr;
		root1 = recursion(root1,last);
		printFlatten(root1);

		cout<<endl;

		inorder(root2);
		cout<<endl;
		last = nullptr;
		root2 = recursion(root2,last);
		printFlatten(root2);
	}
};

// Driver code
int main()
{
	node* root = new node(5);
	root->left = new node(3);
	root->right = new node(7);
	root->left->left = new node(2);
	root->left->right = new node(4);
	root->right->left = new node(6);
	root->right->right = new node(8);

	// Calling required function
	print(flatten(root));

	Solution obj = Solution();
	obj.run();
	return 0;
}