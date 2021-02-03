// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends





//User function template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        vector<pair<int, int>> v;
        vector<int> taken(n);
        
        // we will store all possible heights in a vector
        for(int i = 0; i < n; i++){
            if(arr[i] - k >= 0) v.push_back({arr[i] - k, i});
            v.push_back({arr[i] + k, i});
        }
        sort(v.begin(), v.end());
        int elements_in_range = 0;
        int left = 0;
        int right = 0;
        
        // By two pointer we will traverse v and whenever we will get a range
        // in which all towers are included, we will update the answer. r keeps
        // on increasing and in the way keeps including a new orignial index 
        // encountered on its way.
        while(elements_in_range < n and right < v.size()){
            // If the right indexed element' index at taken is 0 this means 
            // this is the first time this index is visited (a  index atmost twice 
            // can be visited), thus including it in the elements_in_range.
            if(taken[v[right].second] == 0) elements_in_range++;                            //  -|
            // Visited right indexed element's index is increased as it has been            //   |
            // visited.                                                                     //   | SAME LOGIC
            taken[v[right].second]++;                                                       //   | right
            // Right is increased i.e. the window is extended in the right direction.       //   | forwading
            right++;                                                                        //  -|
        }
        
        // As there are already n elements in elements_in_range. We calculate
        // the possible answer at this stage.
        int ans = v[right - 1].first - v[left].first;
        
        // Now we keep sliding the window.
        while(right < v.size()){
            // If a index at taken is already visited once this, and we need to take left
            // index forward then we have to remove that index from elements_in_range.
            if(taken[v[left].second] == 1) elements_in_range--;                             //   -| SAME LOGIC
            taken[v[left].second]--;                                                        //    | left
            left++;                                                                         //   -| forwading
            
            while(elements_in_range < n and right < v.size()){
                if(taken[v[right].second]==0)elements_in_range++;                           //   -| SAME LOGIC
                taken[v[right].second]++;                                                   //    | right
                right++;                                                                    //   -| forwading
            }
            
            if(elements_in_range == n) ans = min(ans, v[right - 1].first - v[left].first);
            // If code reaches here then it means that we have come to an end of the 
            // vector v and thus elements_in_range is lesser than n.
            else break;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
