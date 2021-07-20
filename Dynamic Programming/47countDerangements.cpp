#include<bits/stdc++.h>
using namespace std;


// Time complexity : O(n^2)
// Space complexity : O(n)
int cntDerangements(int n){
    int dp[n+1] = {0};

    for(int i=0;i<n+1;i++){
        if(i==0 or i==1) dp[i] = 0;
        else if(i==2) dp[2] = 1;
        else dp[i] = (i-1)*(dp[i-2]+dp[i-1]);
    }
    return dp[n];
}


// Time complexity : O(n^2)
// Space complexity : O(n)
int cd(int n){

    // scndLast stores the number of permutations
    // at n-2 index
    // when n==1
    int scndLast = 0;

    // last stores the number of permutations
    // at n-1 index
    // when n==2
    int last = 1;
    int current;

    for(int i=3;i<=n;i++){
        current = (i-1)*(scndLast+last);
        scndLast = last;
        last = current;
    }
    return current;
}


int main(){
    int n = 4;
    cout<<"Count of Derangements is "<<cntDerangements(n)<<endl;
    cout<<"Count of Derangements is "<<cd(n);
    return 0;
}
