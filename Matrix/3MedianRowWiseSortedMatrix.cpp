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
        int min = INT_MAX, max = INT_MIN;
        // Finding the max and min elements in matrix
        for(int i=0;i<r;i++){
            if(matrix[i][0]<min) min = matrix[i][0];
            if(matrix[i][c-1]>max) max = matrix[i][c-1];
        }
        // The desired location of median.
        int req = (r*c+1)/2;
        // Binary search to find the the correct location 
        // of median.
        while(min<max){
            int mid = min+(max-min)/2;
            // place stores the number of elements lower
            // than the mid element of current max and min,
            // if it is less than the required location
            // then the max min are updated accordingly.
            int place = 0;
            for(int i=0;i<r;i++) place += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            if(place<req) min = mid+1;
            else max = mid;
        }
        // The search continues till the end where only two
        // elements are left - max and min. Thus we return the min
        // as this is the correct median.
        return min;
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
