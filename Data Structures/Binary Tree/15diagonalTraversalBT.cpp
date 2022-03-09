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


vector<int> diagonal(Node *root);

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

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void diagPrint(Node *root, int diag_no, map<int,vector<int>> &mp){
    if(!root) return;
    // Diagonal number is the diagonal sequence number
    // starting from 0 as the topmost diagonal and then
    // the rest follows
    
    // The current node's value is pushed into the vector
    // with the key corresponding to the diag_no
    mp[diag_no].push_back(root->data);
    
    // As for each diagonal the nodes are traversed from
    // left to right thus left is processed before right
    // Also for a node in the left of the current node the
    // diagonal number increases by one as that node is
    // present in the diagonal next to the diagonal of the
    // current node
    diagPrint(root->left,diag_no+1,mp);
    // For the right node the diagonal remains the same
    diagPrint(root->right,diag_no,mp);
}

vector<int> diagonal(Node *root)
{
    // your code here
    // The map contains diagonal number as the key
    // and the and a vector containing the data of
    // each node in that particular diagonal sequentially
    map<int,vector<int>> mp;
    diagPrint(root,0,mp);
    vector<int> ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        for(auto e:it->second) ans.push_back(e);
    }
    return ans;
}
