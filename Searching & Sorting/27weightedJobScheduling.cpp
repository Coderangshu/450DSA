class Solution {
public:
    
    // to be used while sorting according to job finish time
    static bool compare(vector<int> job1, vector<int> job2){
        return (job1[1]<job2[1]);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        // vector of vector to store start,end,weight
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++) jobs.push_back({startTime[i],endTime[i],profit[i]});
        
        // sort according to ending time, here we do not merge intervals thus sorting
        // using ending time as this will give the diff b/w start of ith and the prev
        // jobs end in decreasing order
        sort(jobs.begin(),jobs.end(),compare);
        
        // the max weight will be found using dp, we will decide for each job either
        // include or not include in our max weight calculation
        // to reduce the n^2 algo of dp we use binary search to find the latest non
        // intersecting job previous to the current job
        
        // dp will store the max sum of weight of non
        // intersecting jobs upto that job
        vector<int> dp(n);
        // fow 1 st job we do not have any choice we have to take it
        dp[0] = jobs[0][2];
        for(int i=1;i<n;i++){
            // binary search for most recent non intersecting job
            // index stores the last non intersecting job's index
            int index = -1;
            int low = 0, high = i-1;
            while(low<=high){
                int mid = (low+high)>>1;
                // if mid's ending is less or equal to current's starting
                // then assign mid to index and search in upper half to
                // check if more recent non intersecting job exists
                if(jobs[mid][1]<=jobs[i][0]){
                    index = mid;
                    low = mid+1;
                }
                else high = mid-1;
            }
            int incl = jobs[i][2];
            if(index!=-1) incl += dp[index];
            // now the current index of dp will contain the
            // max weight of either including the current job
            // or excluding it (i.e. upto last job)
            dp[i] = max(dp[i-1],incl);
        }
        return dp[n-1];
    }
};
