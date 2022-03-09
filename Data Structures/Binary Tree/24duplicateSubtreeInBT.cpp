// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

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

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

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
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
 
// This function returns empty string if tree
// contains a duplicate subtree of size 2 or more.

// We use the concept of tree serialization and hashing
// We store all possible subtrees in string format in a map
// with each string as key and their respective count as value
// If there is any string having value greater than one we return
// true else false
// TC : O(n)
// SC : O(n)
string dupSubUtil(Node *root, unordered_map<string,int> &subtrees)
{
    if(!root) return "";
    
    // Form inorder representation of all possible subtrees
    string s = '(' + dupSubUtil(root->left,subtrees);
    s += '.'+to_string(root->data)+'.';
    s += dupSubUtil(root->right,subtrees) + ')';
    
    // If string not present in map we add it and its count is 1
    // We store only those strings which are of length>3 because,
    // length 4 strings would be of the leaf nodes, i.e. "(4 )".
    if(s.length()>4) subtrees[s]++;
    
    return s;
}
 

// Using hashmap and BFS to store the parent and its left and right child
// TC & SC is similar to above a bit better than above
bool dupSubUtilBFS(Node *root)
{
	unordered_set<string> us;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *curr = q.front();
		q.pop();
		string s = "";
		if(curr->left) s += to_string(curr->left->data)+" ", q.push(curr->left);
		s += to_string(curr->data)+" ";
		if(curr->right) s += to_string(curr->right->data), q.push(curr->right);
		if(us.count(s)) return true;
		us.insert(s);
	}
	return false;
}

bool dupSub(Node *root)
{
    //your code here
	unordered_map<string,int> subtrees;

	// METHOD 1
	// dupSubUtil(root,subtrees);
    // for(auto it=subtrees.begin();it!=subtrees.end();it++){
    //     if(it->second>1) return true;
    // }
    // return false;

	// METHOD 2
	return dupSubUtilBFS(root)?true:false;
}

// { Driver Code Starts.
int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		//Solution ob;
		cout << dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends
