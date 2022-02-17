class Solution {
private:
    // recursion to try out all possible arrangements
    bool isPossible(vector<int>& jobs, vector<int> &times, int ind, int mid, int k, int n){
        if(ind==n) return true;
        for(int i=0;i<k;i++){
            if(jobs[ind]<=times[i]){
                times[i] -= jobs[ind];
                if(isPossible(jobs,times,ind+1,mid,k,n)) return true;
                times[i] += jobs[ind];
            }
            // if the current time isn't used in any of the jobs 
            // all the way down to the last job available then
            // what's the purpose of trying out the next jobs?
            if(times[i]==mid) return false;
        }
        return false;
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        sort(jobs.begin(),jobs.end(),greater());
        int low = jobs[0], high = n*jobs[0], ans = -1;
        
        // binary search
        while(low<=high){
            int mid = (low+high)>>1;
            vector<int> allotedTime(k,mid);
            bool ans = isPossible(jobs,allotedTime,0,mid,k,n);
            if(ans){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};