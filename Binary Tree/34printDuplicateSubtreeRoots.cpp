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

void printAllDups(Node* root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
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
           if (root == NULL) root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     printAllDups(root);
     cout<<endl;
  }
  return 0;
}// } Driver Code Ends


//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line

unordered_map<string,int> subtrees;

// This is the function used in 24duplicateSubtreeInBT
// the difference only being here the leadf nodes are
// also included as subtrees thus string length >=3 is
// accepted instead of only >3
// the second difference is now as we need to print the
// root of each subtree we store the roots in a set(which
// stores unique values and also sorts them)
string dupSubUtil(Node *root, set<int> &ans)
{
    if(!root) return "";
    string s = '(' + dupSubUtil(root->left,ans);
    s += root->data+'0';
    s += dupSubUtil(root->right,ans) + ')';
    if(subtrees.find(s)==subtrees.end() and s.length()>=3) subtrees[s] = 1;
    else if(subtrees.find(s)!=subtrees.end() and s.length()>=3){
        subtrees[s] = subtrees[s] + 1;
        ans.insert(root->data);
    }
    return s;
}

void printAllDups(Node* root)
{
    // Code here
    set<int> ans;
    string str = dupSubUtil(root, ans);
    // for(auto it=subtrees.begin();it!=subtrees.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    if(ans.size()==0) cout<<-1;
    else for(auto e:ans) cout<<e<<" ";
}
