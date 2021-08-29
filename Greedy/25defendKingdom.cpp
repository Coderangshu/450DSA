#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int w,h,n;
        cin>>w>>h>>n;
        // row and col will have 1 
        // where there's a tower
        vector<int> col(w,0),row(h,0);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>y>>x;
            row[x-1] = 1;
            col[y-1] = 1;
        }
        
        // to store the gaps in between the rows 
        // which have tower and same for cols
        vector<int> rdiff, cdiff;
        // keep count of 0s as that would be the gap
        // between each of the row/col
        int count = 0;
        for(int i=0;i<w;i++){
            if(col[i]==1){
                cdiff.push_back(count);
                count = 0;
            }
            else count++;
        }
        cdiff.push_back(count);
        
        count = 0;
        for(int i=0;i<h;i++){
            if(row[i]==1){
                rdiff.push_back(count);
                count = 0;
            }
            else count++;
        }
        rdiff.push_back(count);
        
        // max diff of row and col will give the max undefended area
        int maxR = *max_element(rdiff.begin(),rdiff.end());
        int maxC = *max_element(cdiff.begin(),cdiff.end());
        cout<<(maxR*maxC)<<endl;
    }
    return 0;
}
