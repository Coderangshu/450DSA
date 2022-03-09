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



 // } Driver Code Ends
/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    
    Node *temp;
    
    Node* kthSmallest(Node* root, int& k)
    {
        // Pursuing the smallest element than gradually
        // finding the k'th smallest by decrementing k
        // when k becomes 0 this means that the kth
        // smallest element is reached
        
        // base case
        if (!root) return NULL;
     
        // search in left subtree
        Node* left = kthSmallest(root->left, k);
        // if left subtree present, return it for element
        // to be searched in it
        if (left) return left;
     
        // if current element is k'th smallest, return it
        if (--k==0) return root;
     
        // else search in right subtree
        return kthSmallest(root->right, k);
    }
    
    int ans = -1;
    
    void kthSmallest1(Node* root, int &k){
        if(!root) return;
        kthSmallest1(root->left, k);
        if(--k == 0) ans = root->data;
        kthSmallest1(root->right, k);
    }

    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        // Node * ans = kthSmallest1(root,K);
        // if(ans) return ans->data;
        // else return -1;
        kthSmallest1(root, K);
        return ans;
    }
};

// { Driver Code Starts.
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
      //  getline(cin, s);
      Solution obj;
       cout << obj.KthSmallestElement(root, k) << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends
