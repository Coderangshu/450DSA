// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    // Brute force can be done in O(n^2) to check that row
    // which has all 0s and the same index column which 
    // has all 1s (except M[i][i]) than that corresponding 
    // index is the celebrity
    
    // For O(n) solution using the concept of elimination
    // we check for every pair of persons, using a stack we
    // keep all those potential celebrities in the stack
    // then using elimination we remove the ones who aren't
    // one, to do this we check for any of the 2 conditions:
    // if a knows b then a cannot be celebrity
    // if a doesn't know b then b cannot be celebrity
    
    // after all eleminations the last member in stack is
    // still a potential celebrity to confirm it we check
    // the corresponding M[row][col] if all in row are 0s
    // and all in col are 1s(except M[col][col]) then this
    // index is a celebrity
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        // pushing all persons to stack
        for(int i=0;i<n;i++) s.push(i);
        
        // popping 2 person at a time and eliminating
        // the non celebrity and pushing back the potential
        // celebrity, until only 2 person in stack
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            // we check for if a knows b, then a not
            // celebrity, else b not celebrity
            if(M[a][b]==1) s.push(b);
            else s.push(a);
        }
        
        // now as only 1 person as potential celebrity
        // we check corresponding row,col
        // checking col for all 1 except col,col
        for(int i=0;i<n;i++){
            // escaping the col,col cell
            if(i==s.top()) continue;
            // if any of the col becomes 0 then person
            // not a celebrity
            if(M[i][s.top()]==0) return -1;
        }
        
        // checking row if any cell has 1 then not celebrity
        for(int i=0;i<n;i++) if(M[s.top()][i]==1) return -1;
        
        // if both cell and row passed then surely celebrity
        return s.top();
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
