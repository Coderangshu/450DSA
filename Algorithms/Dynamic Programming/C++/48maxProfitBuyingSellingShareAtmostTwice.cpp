// O(n) is the time complexity
// O(1) is the space complexity

#include<bits/stdc++.h>
using namespace std;

// approach used is Hill-Valley

// Example array : 10 22 5 75 65 80
// pictorially representation:
/*                      80
                 75    /
       22       /  \  /
      /  \     /    65
     /    \   /
    10     \ /
            5
*/

// here we buy shares when in valley and sell them when in peak
// thus profit made is (22-10)+(75-5)+(80-65) = 97


// Example array : 2 30 15 10 8 25 80
// pictorially representation:
/*
                        80
                       /
        30            /
       /  \          25
      /    15       /
     /      \      /
    2        10   /
               \ /
                8
*/
// profit -> (30-2)+(80-8) = 100


// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n,max_profit=0;
// 		cin>>n;
// 		for(int i=0;i<n;i++){
// 			int e1,e2;
// 			if(i==0) cin>>e1;
// 			else{
// 				cin>>e2;
// 				if(e2-e1>0) max_profit += e2-e1;
// 				e1 = e2;
// 			}
// 		}
// 		cout<<max_profit<<endl;
// 	}
// 	return 0;
// }



// Using DP approach

int maxProfit(int a[], int n){

    vector<int> profit(n,0);

    // Get the maximum profit with
    // only one transaction
    // allowed. After this loop,
    // profit[i] contains maximum
    // profit from a[i..n-1]
    // using at most one trans.

    int max_price = a[n-1];
    for(int i=n-2;i>=0;i--){
        max_price = max(max_price,a[i]);

        // we can get profit[i] by taking maximum of:
        // a) previous maximum, i.e., profit[i+1]
        // b) profit by buying at a[i] and selling at
        //    max_price
        profit[i] = max(profit[i+1],max_price-a[i]);
    }

    /* Get the maximum profit with two transactions allowed
       After this loop, profit[n-1] contains the result */
    int min_price = a[0];
    for(int i=1;i<n;i++){
        min_price = min(min_price,a[i]);

        // Maximum profit is maximum of:
        // a) previous maximum, i.e., profit[i-1]
        // b) (Buy, Sell) at (min_price, a[i]) and add
        //    profit of other trans. stored in profit[i]
        profit[i] = max(profit[i-1],profit[i]+a[i]-min_price);
    }
    return profit[n-1];
}


int main(){
    int a[] = {10,22,5,75,65,80};
    int na = sizeof(a)/sizeof(int);

    int b[] = {2,30,15,10,8,25,80};
    int nb = sizeof(b)/sizeof(int);

    cout<<maxProfit(a,na)<<endl;
    cout<<maxProfit(b,nb)<<endl;

    return 0;
}
