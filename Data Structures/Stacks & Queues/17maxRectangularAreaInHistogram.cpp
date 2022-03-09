                    

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    
    // brute force : get left and right boundary for each bar
    // find the area and return the max (O(N^2))
    
    // O(5n)~O(n) approach : using concept of next greatest element
    // get the left and right smallest for each bar and then compute
    // area and return max, space - O(3n)
    
    // O(n) approach : using the same concept of next greatest element
    // but herein its done in one traversal, space - O(n)
    
    //Function to find largest rectangular area possible in a given histogram.
    
    // O(5n) approach
    long long getMaxArea1(long long arr[], int n)
    {
        // Your code here
        // vector to store left and right smallest for each bar
        vector<long long> ls(n), rs(n);
        
        // we use stack to get the above
        // the stack here stores the index of decreasing order 
        // of numbers in arr from top to bottom
        stack<long long> s;
        
        // getting the left smallest for each bar
        for(int i=0;i<n;i++){
            // if stack empty means theres no number in arr
            // less than current number thus left boundary
            // is the limit
            if(s.empty()) ls[i] = 0;
            else{
                // pop until top's value(number) is less than current 
                while(!s.empty() and arr[s.top()]>=arr[i]) s.pop();
                if(s.empty()) ls[i] = 0;
                else ls[i] = s.top();
            }
            s.push(i);
        }
        
        // clear stack to be reused
        while(!s.empty()) s.pop();

        // getting the right smallest for each bar
        for(int i=n-1;i>=0;i--){
            if(s.empty()) rs[i] = n-1;
            else{
                while(!s.empty() and arr[s.top()]>=arr[i]) s.pop();
                if(s.empty()) rs[i] = n-1;
                else rs[i] = s.top();
            }
            s.push(i);
        }
        
        long long maxAr = INT_MIN;
        for(int i=0;i<n;i++) maxAr = max(maxAr,(rs[i]-ls[i]-1)*arr[i]);
        
        return maxAr;
    }
    
    // O(n) approach
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        
        //{
        // the intuition here is traverse from left
        // keep pushing the values into stack uptill
        // increasing when smaller than top found then
        // we know that for all the previous bars this
        // is the right smallest boundary, and also for
        // the left smallest boundary each of the previous
        // bars will be the one just below the top for each
        // of the top bars thus for the top bar we get both
        // left and right boundary we calculate area and pop
        // and do the same until stack empty or s.top()<current
        //}
        
        stack<long long> s;
        long long maxAr = INT_MIN;
        
        // Notice here we go one extra loop that signifies
        // we are considering a bar of height 0 at the end
        // so that we can calculate the remaining bar areas
        // and clear out the stack 
        for(int i=0;i<n+1;i++){
            // we need to clear out the stack after completing
            // thus we go into the while loop when i==n
            while(!s.empty() and (i==n or arr[s.top()]>=arr[i])){
                // we have reached the right smallest boundary for
                // all previous bars
                // calculate area for each previous bar and pop
                // untill bar height is less than the current height
                // or empty
                long long height = arr[s.top()];
                s.pop();
                int width;
                if(s.empty()) width = i;
                else width = i-s.top()-1;
                maxAr = max(maxAr,height*width);
            }
            s.push(i);
        }
        return maxAr;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
