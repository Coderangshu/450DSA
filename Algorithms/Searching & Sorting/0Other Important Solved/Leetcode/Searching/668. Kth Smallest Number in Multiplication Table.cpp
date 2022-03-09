// Do binary search for all the # in table, from 0 to m*n
// Consider each mid as the kth smallest
// find the count of the smaller # then the current kthSmallest
//  if the count is more than k then search in lower half, else
//  search in the higher half

// to count go through every m rows and check last # of that row
// if its greater than current kthSmallest than this row has n
// # smaller than current kthSmallest, else there are kthSmallest/i
// # in that row smaller than kthSmallest

class Solution {
  public:
    bool kSmaller(int n, int m, int num, int k) {
            int c = 0;
            for (int i = 1; i <= m; i++)
                c += min(n, num/i);
            
            return c >= k;
        }
    
    int findKthNumber(int m, int n, int k) {
            int lo = 0, hi = m*n, mid, res;
            
            while (lo < hi) {
                        mid = lo + (hi - lo) / 2;
                        
                        if (kSmaller(n, m, mid, k)) hi = mid;
                        else lo = mid + 1;
                    }
            
            return lo;
        }
};
