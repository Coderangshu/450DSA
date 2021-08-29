#include<bits/stdc++.h>
using namespace std;

// recursive function to print each transaction
// in each call between the max cred and max debt
void minCashFlowUtil(vector<int> amt){
	// get max credit and max debit indices
	int mxCred = max_element(amt.begin(),amt.end())-amt.begin();
	int mxDebt = min_element(amt.begin(),amt.end())-amt.begin();
	
	// if both are 0 means all transactions settled
	if(amt[mxCred]==0 and amt[mxDebt]==0) return;

	// find min of mxCred and mxDebt that amount will be transferred from one to other
	int minAmt = min(amt[mxCred],-amt[mxDebt]);

	// make transactions credit gets the minAmt and debt gives the minAmt
	// thus cred's new cred and debt's new debt will be reduced
	amt[mxCred] -= minAmt;
	amt[mxDebt] += minAmt;

	// print the transaction
	cout<<"Person "<<mxDebt<<" pays "<<minAmt<<" to Person "<<mxCred<<endl;

	// recurse for the rest unbalanced creds and debts untill all are balanced(0)
	minCashFlowUtil(amt);
}

int main()
{
	// N friends
	int N = 3;
    // graph[i][j] indicates the amount
	// that person i needs to pay person j
    int graph[N][N] = {{0 ,1000 ,2000},
                       {0 ,0    ,5000},
                       {0 ,0    ,0   }};

	// to store the total cred of each
	vector<int> amt(N,0);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			amt[i] += (graph[j][i]-graph[i][j]);
	for(auto e:amt) cout<<e<<" ";
	cout<<endl;
	minCashFlowUtil(amt);
    return 0;
}
