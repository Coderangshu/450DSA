#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void maxHeapify(int arr[], int root, int n){
    int largest = root;
    int l = 2*root+1;
    int r = 2*root+2;
    if (l<n && arr[l]>arr[largest]) largest = l;
    if (r<n && arr[r]>arr[largest]) largest = r;
    if (largest!=root){
        swap(arr[largest], arr[root]);
        maxHeapify(arr, largest, n);
    }
}

void heapSort(int arr[], int n, int k){
    for(int i=n/2-1;i>=0;i--) maxHeapify(arr, i, n);
    for(int i=n-1;i>=k-1;i--){
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}

int kthSmallest(int arr[], int l, int r, int k)
{
    heapSort(arr, r+1, k);
    // printArray(arr, n);
    return arr[k-1];
}

int main(){
  int test_case;
  cin>>test_case;
  while(test_case--){
    int number_of_elements;
    cin>>number_of_elements;
    int a[number_of_elements];
    for(int i=0;i<number_of_elements;i++) cin>>a[i];
    int k;
    cin>>k;
    cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
  }
  return 0;
}
