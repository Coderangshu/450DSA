class Solution{
public:

    // Function to find the minimum amount
    // to buy all candies
    int findMinimum(int arr[], int n, int k)
    {
        int res = 0;
        // buy candies from first and take k from last
        for (int i = 0; i < n; i++) {
            // Buy current candy
            res += arr[i];
            // And take k candies for free from the last
            n -= k;
        }
        return res;
    }
     
    // Function to find the maximum amount to buy all candies
    int findMaximum(int arr[], int n, int k)
    {
        int res = 0, index = 0;
     
        // buy candies from last and take k from first
        for (int i = n - 1; i >= index; i--)
        {
            // Buy candy with maximum amount
            res += arr[i];
     
            // And get k candies for free from the starting
            index += k;
        }
        return res;
    }

    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        // sort candies according to price
        sort(candies,candies+N);
        vector<int> ans;
        ans.push_back(findMinimum(candies,N,K));
        ans.push_back(findMaximum(candies,N,K));
        return ans;
    }
};
