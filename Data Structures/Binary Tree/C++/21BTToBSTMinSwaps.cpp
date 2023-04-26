#include<bits/stdc++.h>
using namespace std;

// The concept used herein is that a BST's inorder traversal
// is a sorted list, thus for a given tree we convert it into
// a inorder way and then try to sort it with minimum swaps

// Inorder Traversal of Binary Tree
void inorder(int a[], vector<int> &v, int n, int index)
{
    // index is the index of current node's data
    
    // if index is greater or equal to vector size
    if(index>=n) return;
    
    // Follow the standard procedure for inorder traversal
    // Note: root->left herein is 2*indexCurrent+1 and
    //       root->right herein is 2*indexCurrent+2
    
    // Process left child of current node
    inorder(a,v,n,2*index+1);
     
    // push elements in vector
    v.push_back(a[index]);
    
    // Process right child of current node
    inorder(a,v,n,2*index+2);
}

// iterating through sorted list and placing each element in original position
// in the process counting swaps
int iterativeMethod(vector<pair<int,int>> &v) {
    int ans = 0;
    // We traverse through the sorted vector this contains the inorder
    // in sorted way, now we need to count the minimum swaps
    for(int i=0;i<v.size();i++){
        // We swap until the ith pair to the index position indicated by pair's second
        // i.e. the original position of that element in the unsorted vector
        // So as to make it same as the unsorted vector
        while(i!=v[i].second) {
            swap(v[i],v[v[i].second]);
            ans++;
        }
    }
    return ans;
}

// minSwaps can be calculated form the number of cycles present
// min. no. of swaps = sum(#elements in each cycle - 1)
int dfs(vector<pair<int,int>> &v, int u, vector<int> &vis, vector<int> &path) {
    if(vis[u]==1) {
        bool cycleStart = false;
        int nodeCount = 0;
        for(auto &e:path) {
            if(e==u) cycleStart = !cycleStart;
            if(cycleStart) nodeCount++;
        }
        return nodeCount;
    }
    vis[u] = 1;
    path.push_back(u);
    int ans = dfs(v,v[u].second,vis,path);
    path.pop_back();
    return ans;
}

int cycleMethod(vector<pair<int,int>> &v) {
    int n = v.size();
    vector<int> vis(n,0), path;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(vis[i]==1) continue;
        if(i==v[i].second) {
            vis[i] = 1;
            continue;
        }
        // adding to answer nodeCount in current node's cycle - 1
        ans += dfs(v,i,vis,path)-1;
    }
    return ans;
}

// Function to find minimum swaps to sort an array
int minSwaps(vector<int> &v){
    vector<pair<int,int>> sorted_vec(v.size());
    for(int i=0;i<v.size();i++) sorted_vec[i].first = v[i], sorted_vec[i].second = i;
    sort(sorted_vec.begin(), sorted_vec.end());
    
    return iterativeMethod(sorted_vec);
    // return cycleMethod(sorted_vec);
    
}

int main()
{
    // case 1
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    inorder(a, v, n, 0);
    cout<<"Minimum swaps required are "<<minSwaps(v)<<endl;

    // case 2
    int b[] = { 1, 2, 3 };
    int nb = sizeof(b) / sizeof(b[0]);
    vector<int> vb;
    inorder(b, vb, nb, 0);
    cout<<"Minimum swaps required are "<<minSwaps(vb)<<endl;
}
