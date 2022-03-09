// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
    public:
    /// Helper function to print Inorder traversal
    void inorder(Node* root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    
    // mirrorify function takes two trees,
    // original tree and a mirror tree
    // It recurses on both the trees,
    // but when original tree recurses on left,
    // mirror tree recurses on right and
    // vice-versa
    void mirrorify(Node* root, Node* &mirror)
    {
        if (root == NULL) {
            mirror = NULL;
            return;
        }
    
        // Create new mirror node from original tree node
        mirror = newNode(root->data);
        mirrorify(root->left, mirror->right);
        mirrorify(root->right, mirror->left);
    }

};

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        // Print inorder traversal of the input tree
        printf("Inorder of original tree: ");
        ob.inorder(root);
        Node* mirror = NULL;
        ob.mirrorify(root, mirror);
    
        // Print inorder traversal of the mirror tree
        printf("\nInorder of mirror tree: ");
        ob.inorder(mirror);
    }
    return 0;
}
