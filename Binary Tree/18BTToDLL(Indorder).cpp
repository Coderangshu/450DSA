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
/* Structure for tree and linked list

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

// This function should return head to the DLL
class Solution
{
    public: 
    
    void inorderRecursive(Node* root, Node* &head, Node* &tail){
        if(!root) return;
        
        // The standard inorder procedure using recursion is followed
        // here, i.e. Process left node print root node process right node
        
        // Left node is called recursively
        inorderRecursive(root->left, head, tail);
        
        // Storing the root in the DLL
        
        // If head of DLL is empty then root is new head
        // i.e. As the left is processed first thus the head
        // will be the leftmost leaf node
        if(!head) head = root;
        
        // We assign tail to the root->left as the root is
        // joined right of the tail of DLL
        // Note:the tail remains NULL for the head of DLL
        root->left = tail;
        
        // If tail isn't NULL then assign root to the right of
        // tail as the root will become the last element in the
        // DLL now
        if(tail) tail->right = root;
     
        // root is the new tail
        tail = root;
     
        // Right node is called recursively
        inorderRecursive(root->right, head, tail);
    }
    
    //Function to convert binary tree to inorder doubly linked list
    Node * bToDLL(Node *root)
    {
        // your code here
        
        // We keep track of the head and tail of the DLL
        Node *head = NULL, *tail = NULL;
        inorderRecursive(root,head,tail);
        return head;
    }
};



// { Driver Code Starts.


/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}

/* Driver program to test size function*/
int main()
{
  int t;
  cin >> t;
  getchar();
  
  while (t--)
  {
     string inp;
     getline(cin, inp);
     Node *root = buildTree(inp);
     
     Solution ob; 
     Node *head = ob.bToDLL(root);
     printList(head);

  }
  return 0;
}

  // } Driver Code Ends
