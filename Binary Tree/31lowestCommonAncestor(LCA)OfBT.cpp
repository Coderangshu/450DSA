  // } Driver Code Ends

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

 // } Driver Code Ends
/* A binary tree node

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

Node * newNode(int);

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    
    // This function returns pointer to LCA of two given values n1 and n2.
    Node * findLCA(Node* root, int n1, int n2, int &count)
    {
        // Base case
        if (root == NULL) return NULL;
     
        // If either n1 or n2 matches with root's data, report
        // the presence by returning root (Note that if a data is
        // ancestor of other, then the ancestor data becomes LCA
        if (root->data == n1 || root->data == n2){
            count += 1;
            Node *left_lca  = findLCA(root->left, n1, n2, count);
            Node *right_lca = findLCA(root->right, n1, n2, count);
            return root;
        }
     
        // Look for keys in left and right subtrees
        Node *left_lca  = findLCA(root->left, n1, n2, count);
        Node *right_lca = findLCA(root->right, n1, n2, count);
     
        // If both of the above calls return Non-NULL, then one data
        // is present in once subtree and other is present in other,
        // So this node is the LCA
        if (left_lca && right_lca){
            count += 1;
            return root;
        }
     
        // Otherwise check if left subtree or right subtree is LCA
        return (left_lca != NULL)? left_lca: right_lca;
    }
    
    
    Node* lca1(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       // count maintains the number of nodes found out of
       // n1 and n2. Thus count can have three values 0,1 or 2
       // 0 no nodes found, 1 means one of n1 or n2 found, 2
       // means both found
       int count = 0;
       Node *ans = findLCA(root,n1,n2,count);
       // If count is 1 or 0 means only one of n1 or n2 is found
       // or both not found, thus no LCA present
       if(count<=1){
           Node *nullNode = newNode(-1);
           return nullNode;
       }
       // Else count is 2 meaning both nodes have been found,
       // thus LCA present
       else return ans;
    }

    Node* lca(Node* root, int n1, int n2){
        if(!root or root->data==n1 or root->data==n2) return root;
        Node *left = lca(root->left,n1,n2);
        Node *right = lca(root->right,n1,n2);
        if(!left) return right;
        else if(!right) return left;
        else return root;
    }

};

// { Driver Code Starts.

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}
  // } Driver Code Ends
