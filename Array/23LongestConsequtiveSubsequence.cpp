// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}// } Driver Code Ends


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
  unordered_set<int> s;                  // this is a hash table of all the elements from the array.
  for(int i=0;i<N;i++) s.insert(arr[i]);
  int ans = 0;
  for(int i=0;i<N;i++){
      if(s.find(arr[i]-1)==s.end()){     // this is to check that this element is the first number of the contiguous sequence,
					 // if a number before this is found than this number will be skiped and the next element will be checked for the same and so on.
          int j = arr[i];
          while(s.find(j)!=s.end()) j++;
          ans = max(ans,j-arr[i]);
      }
  }
  return ans;
}
