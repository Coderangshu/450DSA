// C++ program to merge two BST into a single balanced BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};



// Method: We store the inorder traversal for both the given trees, both are already sorted
// now we know to merge 2 sorted arrays it takes time n+m where n and m are lengths of both
// arrays respectively. This 3rd merged sorted array is sent to form the balanced binary search
// tree as done in previous 10BSTToBalancedBST




// This merging takes O(n1+n2) time
vector<Node*> mergeArrays(vector<Node*> arr1, vector<Node*> arr2, int n1,int n2){
    int i = 0, j = 0;
    vector<Node*> arr3;
    // Traverse both array
    while (i<n1 and j <n2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (arr1[i]->data < arr2[j]->data) arr3.push_back(arr1[i++]);
        else arr3.push_back(arr2[j++]);
    }
    // Store remaining elements of first array
    while (i < n1) arr3.push_back(arr1[i++]);
    // Store remaining elements of second array
    while (j < n2) arr3.push_back(arr2[j++]);
    return arr3;
}

void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
	// Base case
	if (root==NULL) return;
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}

Node* buildTreeUtil(vector<Node*> &nodes, int start,int end)
{
	// base case
	if (start > end) return NULL;

	// Get the middle element and make it root
	int mid = (start + end)/2;
	Node *root = nodes[mid];

	// Using index in Inorder traversal, construct
	// left and right subtress
	root->left = buildTreeUtil(nodes, start, mid-1);
	root->right = buildTreeUtil(nodes, mid+1, end);

	return root;
}

Node* mergeTree(Node* root1, Node* root2){
	vector<Node *> nodes1, nodes2;
	storeBSTNodes(root1, nodes1);
	storeBSTNodes(root2, nodes2);
    
    int n = nodes1.size(), m = nodes2.size();
    vector<Node *> sortedMerged = mergeArrays(nodes1,nodes2,n,m);
    
	int l = n+m;
	return buildTreeUtil(sortedMerged, 0, l-1);
}

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// Driver program
int main()
{
	// Create following tree as first balanced BST
    //          100
    //          / \
    //         50 300
    //        / \
    //       20 70
    Node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
 
    // Create following tree as second balanced BST
    //        80
    //       / \
    //      40 120
    Node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);

	Node *root = mergeTree(root1,root2);

	printf("Preorder traversal of balanced BST is : \n");
	preOrder(root);

	return 0;
}

