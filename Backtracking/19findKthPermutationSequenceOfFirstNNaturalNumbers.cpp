#include<bits/stdc++.h>
using namespace std;

// To optimize the above method mentioned above, observe that
// the value of k can be directly used to find the number
// at each index of the sequence.


//     The first position of an n length sequence is occupied
//     by each of the numbers from 1 to n exactly n! / n that
//     is (n-1)! number of times and in ascending order. So
//     the first position of the kth sequence will be occupied
//      by the number present at index = k / (n-1)!
//      (according to 1-based indexing).

//     The currently found number can not occur again so it
//     is removed from the original n numbers and now the
//     problem reduces to finding the ( k % (n-1)! )th
//     permutation sequence of the remaining n-1 numbers.

//     This process can be repeated until we have only one
//     number left which will be placed in the first position
//     of the last 1-length sequence.


//     The factorial values involved here can be very large
//     as compared to k. So, the trick used to avoid the
//     full computation of such large factorials is that as
//     soon as the product n * (n-1) * … becomes greater than
//     k, we no longer need to find the actual factorial
//     value because:

//     k / n_actual_factorial_value = 0
//     and k / n_partial_factorial_value = 0
//     when partial_factorial_value > k

int findFirstNumIdx(int &k, int n){
	// if n is 1 means last element left in
	// set thus return index as 0
	if(n==1) return 0;

	// we need (n-1)! thus decrementing n
	n--;

	// actual factorial = n!
	// partial factorial = n*(n-1)*(n-2)*... upto <=k
	int partialFact = n;

	while(k>=partialFact and n>1){
		partialFact *= (n-1);
		n--;
	}

	int frstInd = k/partialFact;
	k %= partialFact;

	return frstInd;
}

string findKthPermutation(int n, int k){
	string ans = "";

	// set to store 1 to n
	set<int> s;
	for(int i=1;i<=n;i++)
		s.insert(i);

	// decrementing k to get 0 indexed format
	k -= 1;

	auto itrInSet = s.begin();
	// to get the n digits of the kth permutation
	for(int i=0;i<n;i++){
		int frstInd = findFirstNumIdx(k,n-i);
		// move the itr to the position which
		// has the first digit of the ans
		advance(itrInSet,frstInd);

		// itrInSet indicates the index of that
		// number that is to be in the first
		// position in the answer
		ans += (to_string(*itrInSet));

		// remove digit added to ans as theres no
		// repetation
		s.erase(itrInSet);

		// reset itrInSet to begining of the set
		itrInSet = s.begin();
	}
	return ans;
}

int main(){
	int n = 3, k = 4;

	string ans = findKthPermutation(n,k);
	cout<<ans<<endl;

	return 0;
}
