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



Node* insert(Node* node, int data);

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

       getline(cin, s);
        int k = stoi(s);
       // getline(cin, s);

        insert(root, k);
        vector<int> v;
        inorder(root, v);
        for(int i=0;i<v.size();i++)
            cout << v[i] << " ";
        cout << endl;

       //cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends




//Function to insert a node in a BST.

Node* search(Node* root, int key)
{
    // Base Cases
    // root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);
    // Key is smaller than root's key
    return search(root->left, key);
}

Node* insert(Node* root, int Key)
{
    // Your code here
    // if Key isn't present in tree then we insert
    if(!search(root,Key)){
        // Insert node, if root is NULL.
        // as the desired location is reached
        if (!root) return new Node(Key);
     
        // Insert data.
        if (Key > root->data){
            // Insert right node data, if the 'Key'
            // to be inserted is greater than 'root' node data.
     
            // Process right nodes.
            root->right = insert(root->right, Key);
        }else{
            // Insert left node data, if the 'Key'
            // to be inserted is greater than 'root' node data.
     
            // Process left nodes.
            root->left = insert(root->left, Key);
        }
        // Return 'root' node, after insertion.
        return root;
    }
    else return root;
}

