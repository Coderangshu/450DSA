 // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
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

 // } Driver Code Ends
/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    int treeHeight(Node *root){
        if(!root) return 0;
        int lHeight = treeHeight(root->left);
        int rHeight = treeHeight(root->right);
        return max(lHeight,rHeight)+1;
    }
    
    // This function recursively stores the elements of each
    // level traversing from left to right in each level
    void printLevelRecursive(Node *root, int height, vector<int> *ans){
        // Height = 1 means the tree now has only one node
        if(height<=1){
            if(root) ans->push_back(root->data);
        }
        // When Height > 1
        else{
            if(root->left) printLevelRecursive(root->left,height-1,ans);
            if(root->right) printLevelRecursive(root->right,height-1,ans);
        }
    }
    
    // this function iteratively stores the elements in ans
    // The root is pushed into the queue, then a while loop
    // is started until queue is empty. Inside we push_back
    // queue.front's data into ans, and pop node from queue,
    // we at the same time push first nodr->left then node->
    // right into the queue, and thus the loop continues,
    // giving us the BFT in the ans vector.
    void printLevelIterative(Node *root, vector<int> *ans){
        if(!root) return;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            ans->push_back(node->data);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
     }
    
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      
      // Iterative method
      printLevelIterative(node,&ans);
      
      // Recursive method
      // We calculate the number of levels
    //   int height = treeHeight(node);
      // For loop for traversing each level
    //   for(int i=1;i<=height;i++) printLevelRecursive(node,i,&ans);
      return ans;
    }
};

// { Driver Code Starts.

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  printf("%d ", node->data);

  inOrder(node->right);
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

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        vector <int> res = ob.levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
  }
  return 0;
}


  // } Driver Code Ends
