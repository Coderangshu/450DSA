#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int middle(int A, int B, int C){
        if(A>B) return B>C?B:min(A,C);
        else return  A>C?A:min(B,C);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}
