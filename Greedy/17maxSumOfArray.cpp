 class Solution{
	public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        unsigned long long int m = 1000000007;
        sort(a,a+n);
        unsigned long long int sum = 0;
        for(int i=0;i<n;i++){
            unsigned long long int prod = ((unsigned long long int)a[i]%m*(unsigned long long int)i%m)%m;
            sum = (sum%m+prod%m)%m;
        }
        return (int)sum%m;
    }
};
