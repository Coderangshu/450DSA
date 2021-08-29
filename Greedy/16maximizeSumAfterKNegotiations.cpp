class Solution{
	public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);

        // converting min(all,k) negatives to positive
        for(int i=0;i<n and k>0;i++){
            if(a[i]<0){
                a[i] = -a[i];
                k--;
            }
        }

        long long int sum = accumulate(a,a+n,0);

        // now condition may occur where all are positive or some are
        // negative but is k!=0, now we find the smallest (maybe +ve/-ve)
        // and alternate sign leftover k times if then the number is
        // negative we remove the abs value of it from sum and also add it
        // to the sum

        // if k is even altering would keep min element same
        // if k is odd the min element sign would be reversed
        // thus we modify only when k is odd
        if(k&1){
            long long int minElem = *min_element(a,a+n);
            sum -= 2*(minElem);
        }
        return sum;
    }
};
