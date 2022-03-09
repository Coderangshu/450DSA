// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    void printLeaves(Node *root, vector<int> &ans_leaf){
        if(!root) return;
        // As the leaves are to be printed left to right hence
        // left then right is processed
        printLeaves(root->left,ans_leaf);
        // When leaf node is reached print the node
        if(!root->left and !root->right) ans_leaf.push_back(root->data);
        // then continue with the right node
        printLeaves(root->right,ans_leaf);
    }

    void printLeftBoundary(Node *root, vector<int> &ans_left){
        // This prints the right boundary in a top to bottom way.
        if(!root) return;
        // Left node is given the first preference in this 
        // function as it is the left boundary printer else
        // we look into the right node as that will be the boundary
        // if left node isn't present.
        
        if(root->left or root->right) ans_left.push_back(root->data);

        // If left node present
        if(root->left) printLeftBoundary(root->left,ans_left);

        else if(root->right) printLeftBoundary(root->right,ans_left);
        // We avoid the leaf nodes to avert repeatation
    }
    
    void printRightBoundary(Node *root, vector<int> &ans_right){
        // This prints the right boundary in a bottom up way.
        if(!root) return;
        // Right node is given the first preference in this 
        // function as it is the right boundary printer else
        // we look into the left node as that will be the boundary
        // if right node isn't present.
        
        // If right node present
        if(root->right) printRightBoundary(root->right,ans_right);

        // If right node not present
        else if(root->left) printRightBoundary(root->left,ans_right);

        // We avoid the leaf nodes to avert repeatation
        if(root->left or root->right)  ans_right.push_back(root->data);
    }

    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> ans(1,root->data);
        
        printLeftBoundary(root->left,ans);
        printLeaves(root->left,ans);
        printRightBoundary(root->right,ans);
        
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
