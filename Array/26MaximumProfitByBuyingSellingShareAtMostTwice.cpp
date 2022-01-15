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


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,max_profit=0;
		cin>>n;
		for(int i=0;i<n;i++){
			int e1,e2;
			if(i==0) cin>>e1;
			else{
				cin>>e2;
				if(e2-e1>0) max_profit += e2-e1;
				e1 = e2;
			}
		}
		cout<<max_profit<<endl;
	}
	return 0;
}
