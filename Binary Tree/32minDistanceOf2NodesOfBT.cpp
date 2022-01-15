// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
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

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
   
   
// This function returns the lowest common ancestor of
// two given nodes
Node * findLCA(Node* root, int n1, int n2, int &count){
    if (root == NULL) return NULL;

    if (root->data == n1 or root->data == n2){
        count += 1;
        Node *left_lca  = findLCA(root->left, n1, n2, count);
        Node *right_lca = findLCA(root->right, n1, n2, count);
        return root;
    }
    
    Node *left_lca  = findLCA(root->left, n1, n2, count);
    Node *right_lca = findLCA(root->right, n1, n2, count);

    if (left_lca && right_lca){
        count += 1;
        return root;
    }
    
    return (left_lca != NULL)? left_lca: right_lca;
}

// Find height of given data value from the root
// (herein the root is the LCA)
int findHeight(Node *root, int k, int height){
    if(root == NULL) return -1;
    if(root->data == k) return height;
 
    int left = findHeight(root->left, k, height+1);
    if (left == -1)
       return findHeight(root->right, k, height+1);
    return left;
}

int findDist(Node* root, int a, int b) {
    // Your code here
    
    // We find the LCA, if present calculate the
    // distance of LCA and both the nodes then
    // return sum of distance of both the nodes
    int count = 0;
    Node *ans = findLCA(root,a,b,count);
    if(count<=1) return 1;
    int height1 = findHeight(ans,a,0);
    int height2 = findHeight(ans,b,0);
    return height1+height2;
}
