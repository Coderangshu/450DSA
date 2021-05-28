#include <bits/stdc++.h>
using namespace std;
 
// custom data type for tree building
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* constructTree(string s, int &start){
    // base condition
    // Either string size will be 0 or start will
    // reach the end of the given string
    if(s.length()==0 or start>=s.length()) return NULL;
    
    // Constructing a number from the string until either
    // '(' or ')' is reached
    int num = 0;
    while(start<s.length() and s[start]!='(' and s[start]!=')'){
        int tn = (int)(s[start]-'0');
        num = num*10 + tn;
        start = start+1;
    }
    
    Node * root = new Node(num);
    
    // If start has reached end then return root
    if(start>=s.length()) return root;
    
    // While parsing the string if we encounter a '(' then we start
    // forming it as the left child node to the root
    if(start<s.length() and s[start]=='('){
        start = start + 1;
        root->left = constructTree(s,start);
    }
    // When a ')' is reached this means that the left node has ended
    if(start<s.length() and s[start]==')') start = start + 1;
    
    // As soon we get the second '(' we start forming it as the
    // right node to the root
    if(start<s.length() and s[start]=='('){
        start = start + 1;
        root->right = constructTree(s,start);
    }
    if(start<s.length() and s[start]==')') start = start + 1;
    return root;
}

void preorder(Node* root)
{
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    string s = "4(2(3)(1))(6(5))";
    // cin>>s;
    // start is a index pointing to the current
    // location of the pointer while parsing the
    // input string to form the tree
    int start = 0;
    Node* root = constructTree(s, start);
    preorder(root);
    return 0;
}
