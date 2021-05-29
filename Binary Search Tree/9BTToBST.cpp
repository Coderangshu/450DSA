// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

void printInorder (struct Node* node)
{
    if (node == NULL)
    return;

    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
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
//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    
    // Approach a naive exploitation of the fact that an inorder of BST is sorted
    // the BT given to us is converted to inorder representation and stored in an
    // array, now we sort this array and then using this array we fill up the data
    // in the BT in an inorder way this would maintain the structure of the original
    // BT but values in it are altered so as the result produces a Binary Search Tree
    
    
  
    // A helper function that stores inorder traversal of a tree rooted
    // with node
    void storeInorder(struct Node* node, vector<int> &inorder, int &index_ptr)
    {
        // Base Case
        if (node == NULL)
            return;
     
        // first store the left subtree
        storeInorder(node->left, inorder, index_ptr);
     
        // Copy the root's data
        inorder.push_back(node->data);
        // increase index for next entry
        index_ptr++; 
     
        // finally store the right subtree
        storeInorder(node->right, inorder, index_ptr);
    }
    
    
    // A helper function that copies contents of arr[] to Binary Tree.
    // This function basically does Inorder traversal of Binary Tree and
    // one by one copy arr[] elements to Binary Tree nodes
    void arrayToBST(vector<int> arr, struct Node* root, int &index_ptr)
    {
        // Base Case
        if (root == NULL)
            return;
     
        // first update the left subtree
        arrayToBST(arr, root->left, index_ptr);
     
        // Now update root's data and increment index
        root->data = arr[index_ptr];
        index_ptr++;
     
        // finally update the right subtree
        arrayToBST(arr, root->right, index_ptr);
    }
    
  
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        // base case: tree is empty
        if (root == NULL) return NULL;
     
        // Count the number of nodes in Binary Tree so that
        // we know the size of temporary array to be created
        
        // Create a temp vector arr and store inorder traversal of tree in arr
        vector<int> arr;
        int i = 0;
        storeInorder(root,arr,i);
     
        // Sort the array using library function for quick sort or sort
        // qsort(arr, n, sizeof(arr[0]), compare);
        sort(arr.begin(),arr.end());
     
        // Copy array elements back to Binary Tree
        i = 0;
        arrayToBST(arr,root,i);
     
        // clean vector arr
        arr.clear();
        
        return root;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST (root);
        printInorder(res);
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends	
