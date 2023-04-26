class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(long long i=0;i<n;i++) pq.push(arr[i]);
        long long totSum = 0;
        while(pq.size()>1){
            long long i = pq.top();
            pq.pop();
            i += pq.top();
            pq.pop();
            totSum += i;
            pq.push(i);
        }
        return totSum;
    }
};