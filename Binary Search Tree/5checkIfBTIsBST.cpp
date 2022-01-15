// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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




 // } Driver Code Ends



class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    bool isBSTUtil(struct Node* root, int& prev)
    {
        // traverse the tree in inorder fashion and
        // keep track of prev node
        if(!root) return true;
         else{
            // we check after every process is being called and completed
            if (!isBSTUtil(root->left, prev))
                return false;
            // For BST the root data should be larger than the root->left
            // which is stored in prev
            if (root->data <= prev)
                return false;
            // Assign current to prev
            prev = root->data;
            // We call the right child and return its value
            return isBSTUtil(root->right, prev);
        }
    }
    
    bool isBSTUtil1(Node* root, int min, int max){
        if(!root) return true;
        if(root->data < min || root->data > max) return false;
        return isBSTUtil1(root->left, min, root->data-1) && isBSTUtil1(root->right, root->data+1, max);
    }

    bool isBST(Node* root) 
    {
        // Your code here
        // prev stores the last element in the
        // inorder representation of the tree uptill that
        // node
        int prev = INT_MIN;
        // return isBSTUtil(root, prev);
        return isBSTUtil1(root, INT_MIN, INT_MAX);
    }
};




// { Driver Code Starts.

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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    if(ob.isBST(root)) 
        cout<<"1\n";
        
    else
        cout<<"0\n";
   }
   return 0;
}


//Position this line where user code will be pasted
  // } Driver Code Ends
