// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    // We use Priority Queue(max heap) thus all insertion
    // deletion occurs in O(logn) the first time creation
    // takes O(nlogn) (building heap and heapifying at
    // each step)
    
    // frequency map of each char is created and then the pairs
    // are pushed into a max heap, this gives us the max freq
    // element at the top, this way we can rearrange the heap
    // after every transaction in O(logn) time
    
    
    
    struct comparator{
        bool operator()(pair<char,int> a, pair<char,int> b){
            return (a.second<b.second);
        }
    };
    
    int minValue(string s, int k){
        // code here
        // creating frequency map
        unordered_map<char,int> um;
        for(int i=0;i<s.length();i++) um[s[i]]++;
        
        // building max heap tree
        priority_queue<pair<char,int>,vector<pair<char,int>>,comparator> pq;
        for(pair<char,int> e:um) pq.push(e);
        
        // allowed to do k deletions
        // so we extract the max frequency
        // char and decrement its frequency
        // then reinsert it to the heap
        for(int i=0;i<k;i++){
            auto e = pq.top();
            pq.pop();
            e.second--;
            pq.push(e);
        }
        
        int ans = 0;
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            ans += e.second*e.second;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
