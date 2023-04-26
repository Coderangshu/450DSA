#include<bits/stdc++.h>
using namespace std;

int main(){
	int s,n,m;
	cin>>s>>n>>m;

	// getting total # of sundays
	int x = s/7;
	// non sundays
	int y = s-x;
	// food required
	int sm = s*m;
	// days to buy sm amount of food
	int days = ceil((double)sm/(double)n);
	if(days<=y) cout<<"Yes "<<days<<endl;
	else cout<<"No"<<endl;

	return 0;
}
