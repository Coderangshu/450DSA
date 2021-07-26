        

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// Sliding window concept


vector<long long> printFirstNegativeInteger(
    long long int A[],long long int N, long long int K) {
        queue<long long int> q;
        vector<long long int> ans;
        for(long long int i=0;i<N;i++){
            // pusing into queue if negative
            if(A[i]<0) q.push(i);
            // for all indexed from K-1 to last we get a window
            // of desired length K
            if(i>=K-1){
                // we remove the indexes from queue that are out of
                // of bound for the current window
                while(!q.empty() and q.front()<=i-K) q.pop();
                // if queue is empty then no -ve present in current
                // window push 0 to ans or if present then the q.front()
                // index gives us that number, as the front will be the
                // most first index that's negative inside the current
                // window
                (q.empty())?ans.push_back(0):ans.push_back(A[q.front()]);
            }
            // cout<<"Size "<<q.size()<<" "<<endl;
            // if(i>=K){
            //     cout<<"Vector "<<endl;
            //     for(auto e:ans) cout<<e<<" ";
            //     cout<<endl;
            // }
        }
        return ans;
 }
