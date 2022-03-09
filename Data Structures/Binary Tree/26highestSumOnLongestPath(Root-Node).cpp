// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}// } Driver Code Ends


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
// your task is to complete this function

void sumOfLongRootToLeafPathUtil(Node* root, int sum, int len, int& maxLen, int& maxSum)
{
    // if true, then we have traversed a root to leaf path
    if (!root) {
        // update maximum length and maximum sum
        // according to the given conditions
        if (maxLen < len) {
            maxLen = len;
            maxSum = sum;
        } else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }
  
    // recur for left subtree
    sumOfLongRootToLeafPathUtil(root->left, sum + root->data, len + 1, maxLen, maxSum);
  
    // recur for right subtree
    sumOfLongRootToLeafPathUtil(root->right, sum + root->data, len + 1, maxLen, maxSum);
}

int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	int sum = 0, len = 0, maxLen = 0, maxSum = INT_MIN;
	sumOfLongRootToLeafPathUtil(root,sum,len,maxLen,maxSum);
	return maxSum;
}
