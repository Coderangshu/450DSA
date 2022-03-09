/* C++ program to calculate Kth ancestor of given node */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* kthAncestorDFS(Node *root, int node , int &k, Node* &ans){
	if(!root) return nullptr;
	// first checking if ans is already found, if found we stop the DFS
	// else check if current node is the node we are looking for
	// else send the left of current node to find the desired node
	// if not found in left send right to find the desired node
	// if none satisfies then the leaf node is reached and backtracked
	if(!ans and root->data == node or kthAncestorDFS(root->left,node,k,ans) or kthAncestorDFS(root->right,node,k,ans)){
		if(k>0) {
            k--;
            return root;
        }
		else if(k==0) ans = root;
        // reached here when k<=0
        // implying already found ans
        // no more traversal required
		return nullptr;
	}
}

void inorder(Node *root) {
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Driver program to test above functions
int main()
{
	string treeString;
	getline(cin, treeString);
	Node *root = buildTree(treeString);

    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;

	int k, node;
	cin >> node >> k;
    Node *ans = NULL;
	Node* parent = kthAncestorDFS(root,node,k,ans);
	if (ans) cout<<ans->data<<endl;
	else cout<<"Doesn't exist"<<endl;
	return 0;
}

