#include <bits/stdc++.h>
using namespace std;

// Return the maximum number of stocks bought
int buyMaximumProducts(int n, int k, int price[]){
	vector<pair<int,int>> v;

	// Making pair of stock cost and number of day
	for (int i=0;i<n;i++) v.push_back(make_pair(price[i],i+1));

	// Sorting the vector pair lowest price first
	sort(v.begin(),v.end());

	// Calculating the maximum number of stock count
	int ans = 0;
	for (int i=0;i<n;i++){
		// getting max stocks that can be bought on ith day
		// that would be min of i and k/price of each stock
		int maxStckBought = min(v[i].second,k/v[i].first);
		ans +=  maxStckBought;
		// left over k
		k -= v[i].first * maxStckBought;
	}
	return ans;
}

// Driven Program
int main()
{
	int price[] = { 10, 7, 19 };
	int n = sizeof(price)/sizeof(price[0]);
	int k = 45;

	cout << buyMaximumProducts(n, k, price) << endl;

	return 0;
}

