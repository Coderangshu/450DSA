// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    
    bool chkLevel(Node *root, int level, int &leafLevel){
        // The leftmost leaf node is reached recursively then
        // its level is stored in leafLevel then the subsequent
        // leaf nodes are checked if any of those's level isn't same
        // asthe leafLevel then return false
        
        // NULL node is as true
        if(!root) return true;
        // If leaf node reached
        if(!root->left and !root->right){
            // If this is the first leaf, i.e. leafLevel==0, then
            // the leafLevel is updated to the current level
            if(leafLevel==0){
                leafLevel = level;
                return true;
            }
            // For the consequent leaf nodes the leafLevel 
            // and the current leaf's level is compared and
            // the bool is returned accordingly
            return (leafLevel==level);
        }
        return chkLevel(root->left,level+1,leafLevel) and chkLevel(root->right,level+1,leafLevel);
    }
    
    bool check(Node *root)
    {
        //Your code here
        // Root resides in level 1 thus the current level is 1
        // As no leaf node is traversed as of now the leafLevel
        // contains 0
        int level = 1, leafLevel = 0;
        return chkLevel(root,level,leafLevel);
    }
};

// { Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}
  // } Driver Code Ends
