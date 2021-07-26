// If not understood clearly after reading watch:
// https://www.youtube.com/watch?v=Du881K7Jtk8

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    
    // Can use Brute force with O(n^2) using 2 pointers
    // Below implemented using stack with O(n) (O(n+n))
    // here the while loop takes O(n) because all elements
    // are pushed or poped once or even never
    // and space complexity of O(n)
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        // {Method :
        // stack is used to keep track of the numbers in increasing
        // order from the last in this way when we encounter a number
        // we start from the top of stack and pop until a greater than
        // the current number is found and then the top is the next
        // greater for it, if stack becomes empty then we are sure that
        // theres no greater element than the current itself.
        
        // Note : 
        // If told to look through a circular loop for the next greatest
        // we simply go through a loop of 2n-1 length and use modulus to
        // circle around the loop once.
        // }
        
        stack<long long> s;
        vector<long long> ans(n);
        
        // begining from end of the vector
        // here no circular told else i would have
        // started at 2n-1 instead
        for(int i=n-1;i>=0;i--){
            // removing from stack all less numbers
            // or until empty
            while(!s.empty() and s.top()<=arr[i]) s.pop();
            
            // giving nge of current number the top is stack
            // not empty else giving -1
            if(!s.empty())ans[i] = s.top();
            else ans[i] = -1;
            
            // pushing current to stack
            s.push(arr[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends
