// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

vector<int> reverseLevelOrder(Node* root);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}// } Driver Code Ends


/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

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
    
// As we need the reverse order thus everything is same
// as in level order Iterative method just that now 
// instead of pushing to vector we push to stack which
// is reversing the whole order, but we need to keep
// in mind that as stack reversed everything the final
// result wont have each level reversed only the order
// of each level is reversed thus we need to insert
// the nodes of each level in inserted order into the
// stack such that when the stack is emptied into the
// vector the levels are reversed but the elements in 
// each level are reversed(reversed)# i.e. remains same

// #Note: Here the first reversal is the one which we
// introduce intentionally and the second reversal
// occurs due to the stack behaviour thus we get final
// result as no reversal in case of elements in each
// level, just the order of the levels are reversed.
void printLevelIterative(Node *root, vector<int> *ans){
    if(!root) return;
    stack<Node *> s;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        s.push(node);
        if(node->right) q.push(node->right);
        if(node->left) q.push(node->left);
    }
    while(!s.empty()){
        ans->push_back(s.top()->data);
        s.pop();
    }
}

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    
    // Iterative method(Using stack and queue)
    printLevelIterative(root,&ans);
    
    // Recursive method
    // We calculate the number of levels
    // int height = treeHeight(root);
    // For loop for traversing each level
    // for(int i=height;i>=1;i--) printLevelRecursive(root,i,&ans);
    return ans;
}
