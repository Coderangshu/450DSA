#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n){
    map<int, int> M;
    for(int i=0;i<n;i++) M[arr[i]]++;
    for(int i=0;i<n;i++){
        if(i<M[0]) arr[i] = 0;
        else if(i<M[0]+M[1]) arr[i] = 1;
        else arr[i] = 2;
    }
}

int main() {
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort012(a, n);
    for(int i=0;i<n;i++) cout << a[i]  << " ";
    cout << endl;
  }
  return 0;
}
