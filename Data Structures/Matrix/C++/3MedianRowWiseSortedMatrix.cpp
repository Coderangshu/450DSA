// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here  
        int mn = INT_MAX, mx = INT_MIN;
        // Finding the max and min elements in matrix
        for(int i=0;i<r;i++){
           mn = min(matrix[i][0],mn);
           mx = max(matrix[i][c-1],mx);
        }
        // The desired location of median.
        int req = (r*c+1)/2;
        // Binary search to find the the correct location 
        // of median.
        while(mn<mx){
            int mid = mn+(mx-mn)/2;
            // place stores the number of elements lower
            // than the mid element of current max and min,
            // if it is less than the required location
            // then the max min are updated accordingly.
            int place = 0;
            for(int i=0;i<r;i++) place += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            if(place<req) mn = mid+1;
            else mx = mid;
        }
        // The search continues till the end where only two
        // elements are left - max and min. Thus we return the min
        // as this is the correct median.
        return mn;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends
