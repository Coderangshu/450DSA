// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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


 // } Driver Code Ends



class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    void topViewMap(Node *root, int horDis, int level, map<int, pair<int, int>> &mp){
        // base case
        if(!root) return;
        // if for current horDis there's no node selected then the first node
        // encountered inserted into map.
        if(mp.count(horDis)==0) mp[horDis] = make_pair(root->data,level);
        // if node already present with the current horDis then we check
        // that particular node's level, if the level is lower than the 
        // current node's level then we put this current node in place of the 
        // previous one, as from top view the node that is at the top most
        // for a particular horDis is only visible.
        else if(mp[horDis].second>level) mp[horDis] = make_pair(root->data,level);
        
        // As we need to print the leftmost first thus we process the left before
        // right.
        // For the left the horDis decreases by one as we move to the left and the
        // level increases by one as we go down the tree
        topViewMap(root->left,horDis-1,level+1,mp);
        // For the right the horDis increases by one as we move to the right and the
        // level increases by one as we go down the tree
        topViewMap(root->right,horDis+1,level+1,mp);
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        
        // map to store the pair of node value and its level
        // as the value with the key being the horizontal distance
        // of it w.r.t. the root node.
        // i.e. map =  (vert_dist,(node_val,level))
        // For example if tree is: 
        //     1
        //    / \
        //   2   3
        //    \   
        //     4  
        //      \
        //       5
        //        \
        //         6
        // then 2's hori_dist w.r.t 1 is -1 and for 3 its +1
        // for 4 its 0, 5 its +1, 6 its +2
        map<int, pair<int, int>> mp;
        
        // topViewMap(root,horizontal_distance_from_root,level_of_node,map)
        topViewMap(root,0,1,mp);
        
        // As in the map the entries are sorted according to their key, i.e.
        // the horizontal distance thus the node values are the same as the top view.
        vector<int> ans;
        for (auto it = mp.begin(); it != mp.end(); it++) ans.push_back(it->second.first);
        return ans;
    }
};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
