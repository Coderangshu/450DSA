// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

struct heapNode{
    int val;
    int row;
    int column;
};

void swap(heapNode *a, heapNode *b){
    heapNode t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(heapNode harr[], int root, int row_size){
    int smallest = root;
    int l = 2*root + 1;
    int r = 2*root + 2;
    if(l<row_size and harr[l].val<harr[smallest].val) smallest = l;
    if(r<row_size and harr[r].val<harr[smallest].val) smallest = r;
    if(smallest!=root){
        swap(&harr[root],&harr[smallest]);
        minHeapify(harr,smallest,row_size);
    }
}

void heapifyArray(heapNode harr[], int row_size){
    for(int i = row_size/2-1;i>=0;i--) minHeapify(harr,i,row_size);
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  if(k<=0 || k>n*n) return -1;
  heapNode harr[n];
  for(int i=0;i<n;i++) harr[i] = {mat[0][i],0,i};
  heapifyArray(harr,n);
  heapNode h;
  for(int i=0;i<k;i++){
      h = harr[0];
      int nextVal = (h.row<(n-1))?mat[h.row+1][h.column]:INT_MAX;
      harr[0] = {nextVal,(h.row)+1,h.column};
      minHeapify(harr,0,n);
  }
  return h.val;
}
