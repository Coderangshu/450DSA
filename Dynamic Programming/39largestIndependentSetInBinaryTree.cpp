#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
	node(int val){
		this->data = val;
		this->left = this->right = NULL;
	}
};

// recursive function to find longest
// independent set size
int LISSRecursive(struct node *root){
	if(root==NULL) return 0;
	
	// we have 2 choices either take the
	// current node in the set or reject
	// it, if taken then its children cannot
	// be part of LIS, if not taken then its
	// children can be part of the LIS
	
	// taking current node
	int size_incl = 1;
	if(root->left) size_incl += LISSRecursive(root->left->left)+
								LISSRecursive(root->left->right);
	if(root->right) size_incl += LISSRecursive(root->right->left)+
								 LISSRecursive(root->right->right);

	// rejecting current node
	int size_excl = LISSRecursive(root->left)+LISSRecursive(root->right);

	return max(size_incl,size_excl);
}



// memoized function to find longest
// independent set size
unordered_map<struct node*,int> memo;
int LISSMemoized(struct node *root){
	if(root==NULL) return 0;

    if(memo.find(root)!=memo.end()) return memo[root];

	// we have 2 choices either take the
	// current node in the set or reject
	// it, if taken then its children cannot
	// be part of LIS, if not taken then its
	// children can be part of the LIS

	// taking current node
	int size_incl = 1;
	if(root->left) size_incl += LISSMemoized(root->left->left)+
								LISSMemoized(root->left->right);
	if(root->right) size_incl += LISSMemoized(root->right->left)+
								 LISSMemoized(root->right->right);

	// rejecting current node
	int size_excl = LISSMemoized(root->left)+LISSMemoized(root->right);

	return memo[root] = max(size_incl,size_excl);
}

int main()
{
    /*
                    10
                   /  \
                 20    30
                /  \     \
              40    50    60
                   /  \
                 70    80
    */
    // Let us construct the tree
    // given in the above diagram
    node *root = new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    root->right = new node(22);
    root->right->right = new node(25);

    cout << "Size of the Largest Independent Set is "<< LISSRecursive(root)<<" (Using recursion)";
	cout<<endl;
    cout << "Size of the Largest Independent Set is "<< LISSMemoized(root)<<" (Using memoization)";

    return 0;
}
