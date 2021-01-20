// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int rb = 0, cb = 0;
        vector<int> v;
        while(rb<r and cb<c){
            // Printing horizontal top row.
            for(int i=cb;i<c;i++) v.push_back(matrix[rb][i]);
            rb++;
            for(int i=rb;i<r;i++) v.push_back(matrix[i][c-1]);
            c--;
            if(rb<r){
                for(int i=c-1;i>=cb;i--) v.push_back(matrix[r-1][i]);
                r--;
            }
            if(cb<c){
                for(int i=r-1;i>=rb;i--) v.push_back(matrix[i][cb]);
                cb++;
            }
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
