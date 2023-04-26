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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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


 // } Driver Code Ends
// User Function template for C++

//Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
  // The criteria for any tree to be a heap:
  // (I)  it should be complete tree
  // (II) roots should be greater than children(for max heap only)
  
  // So we check this two properties
  
    // To count nodes in tree in inorder way
    void countNodes(struct Node *root, int &ans){
        if(!root) return;
        countNodes(root->left,ans);
        ans ++;
        countNodes(root->right,ans);
    }
  
    // check tree's completeness
    bool isComplete(struct Node *root, int index, int noOfNodes){
        // base condition
        // no root is always complete
        if(!root) return true;
        
        // if index of certain node is greater than total nodes
        // than then not a complete tree
        if(index>noOfNodes) return false;
        
        // else return the completeness test of left AND right child
        else
            return isComplete(root->left,2*index+1,noOfNodes) 
            and isComplete(root->right,2*index+2,noOfNodes);
    }
  
    // check tree's root greater than child for each node
    bool isArranged(struct Node *root){
        // base condition
        // if leaf node than always true
        if(!root->left and !root->right) return true;
        
        // In heap tree as its always a complete tree thus if any node
        //  doesn't have right node but has a left node belongs to the
        // second last level thus we only need to check for the left child
        // of that particular node
        else if(!root->right) return (root->data>root->left->data);
        
        // If both child nodes present than check if root greater than both
        // child, if so check the same for both left AND right child
        // else not a heap so return false
        else{
            if(root->data>root->left->data and root->data>root->right->data){
                return isArranged(root->left) and isArranged(root->right);
            }
                
            else return false;
        }
    }
  
    bool isHeap(struct Node * tree)
    {
        // code here
        int noOfNodes = 0;
        countNodes(tree,noOfNodes);
        return isComplete(tree,0,noOfNodes) and isArranged(tree);
    }
};

// { Driver Code Starts.


int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if(ob.isHeap(root))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }


    return 0;
}  // } Driver Code Ends
