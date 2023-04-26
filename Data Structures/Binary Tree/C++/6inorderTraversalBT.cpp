// README (IMPORTANT OBSERVATION FOR ITERATIVE APPROACH FOR IN, PRE, POST ORDERS)
/*
inorder is the only different way, the other two are similar

Inorder :
For inorder need to traverse using a cur pointer, only keeping track of parent at each level
using a stack
traverse down cur->left pushing cur to stack until nullptr reached
when nullptr reached cur = top and print cur->val and cur = cur->right

Rest :
For the other two only a stack will solve the problem, store in stack as you traverse down
just keep the order of left and right pushing into the stack
use another stack to reverse answer in case of postorder (also push cur->right before cur->left)
*/


#include <bits/stdc++.h>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to perform inorder traversal on the tree
void inorderRecursive(Node* root)
{
    // return if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Traverse the left subtree
    inorderRecursive(root->left);
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
 
    // Traverse the right subtree
    inorderRecursive(root->right);
}

void inorderIterative(Node* root)
{
    // create an empty stack
    stack<Node*> stack;
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
//     inorderRecursive7(root);
    inorderIterative(root);
    return 0;
}
