// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.
#include <bits/stdc++.h>
using namespace std;

void mergeHeaps(int merged[], int a[], int b[], int n, int m);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        int merged[m + n];
        mergeHeaps(merged, a, b, n, m);

        for (int i = 0; i < n + m; i++) cout << merged[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

void maxHeapify(int arr[], int n, int idx)
{
    // Find largest of node and its children
    if (idx >= n)
        return;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int max;
    if (l < n && arr[l] > arr[idx])
        max = l;
    else
        max = idx;
    if (r < n && arr[r] > arr[max])
        max = r;
  
    // Put maximum value at root and
    // recur for the child with the
    // maximum value
    if (max != idx) {
        swap(arr[max], arr[idx]);
        maxHeapify(arr, n, max);
    }
}
  
// Builds a max heap of given arr[0..n-1]
void buildMaxHeap(int arr[], int n)
{
    // building the heap from first non-leaf
    // node by calling max heapify function
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void mergeHeaps(int merged[], int a[], int b[], int n, int m) {
    // Merging arrays
    for (int i = 0; i < n; i++) merged[i] = a[i];
    for (int i = 0; i < m; i++) merged[n + i] = b[i];
    buildMaxHeap(merged, n + m);
}
