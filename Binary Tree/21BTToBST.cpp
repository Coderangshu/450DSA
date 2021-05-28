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
    inorder(a,v,n,2 *index+2);
}

// Function to find minimum swaps to sort an array
int minSwaps(vector<int> &v){
    vector<pair<int,int>> sorted_vec(v.size());
    for(int i=0;i<v.size();i++) sorted_vec[i].first = v[i], sorted_vec[i].second = i;
    sort(sorted_vec.begin(), sorted_vec.end());
    
    int ans = 0;
    // We traverse thorugh the sorted vector this contains the inorder
    // in sorted way, now we need to count the minimum swaps
    for(int i=0;i<sorted_vec.size();i++){
        // If after sorting the index of a element remains same
        // this means that element is already sorted so no swap
        if(i==sorted_vec[i].second) continue;
        else{
            // We swap the ith pair to the index position indicated by pair's second
            // i.e. the original position of that element in the unsorted vector
            // So as to make it same as the unsorted vector
            swap(sorted_vec[i].first,sorted_vec[sorted_vec[i].second].first);
            swap(sorted_vec[i].second,sorted_vec[sorted_vec[i].second].second);
            ans++;
            
            // If even after swapping the element isn't in its original place
            // this means that the element needs to be swapped again as it had
            // to be done while sorting
            if(i!=sorted_vec[i].second) i--;
        }
    }
    return ans;
}

int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    inorder(a, v, n, 0);
    cout<<"Minimum swaps required are "<<minSwaps(v)<<endl;
}
