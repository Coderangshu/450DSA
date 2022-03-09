// Observation
// 0
// 0 1
// 0 1 1 0
// 0 1 1 0 1 0 0 1
// 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0

// nth row contains twice the # of elements as of n-1 th row
// first half of nth row is similar to n-1 th row
// second half of nth row is compliment to n-1 th row

class Solution {
public:
  int kthGrammar(int n, int k) {
    if(n==1) return 0;
    int mid = pow(2,n-2);
    if(k<=mid) return kthGrammar(n-1,k);
    else return !kthGrammar(n-1,k-mid);
  }
};
