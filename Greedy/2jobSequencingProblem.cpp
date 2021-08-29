class disjointSet{
private:
    vector<int> parent;

public:
    // constructor of disjoint set of size
    // of max deadline
    disjointSet(int n){
        // all days are empty so each of them's
        // latest empty slot is the day themselve
        // doing to +1 as days are 1 indexed
        for(int i=0;i<n+1;i++) parent.push_back(i);
    }
    
    // finding parent by path compression
    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    // in union we assign the parent of time t
    // as time t-1, as the job is to be done at
    // time t thus it gets occupied and thus t-1
    // is the next empty slot that is open for
    // the next job to be assigned
    void Union(int t){
        parent[t] = t-1;
    }
};

class Solution 
{
    public:
    
    static bool compare(Job a, Job b){return a.profit>b.profit;}
    
    
    
    // Method 1:
    //Function to find the maximum profit and the number of jobs done.
    // TC:O(n*maxDeadline) SC: O(maxDeadline)
    // for each n job we search at max from the max deadline to 0
    // to get the lastest empty slot
    vector<int> JobScheduling1(Job arr[], int n) 
    { 
        // your code here
        // sorting from large to small profit
        sort(arr,arr+n,compare);
        
        // keeping array of size max deadline days to store max
        // possible free slots( stores -1) and the filled slots
        // at ith index denotes the job id that is to be done
        // at that indexed deadline i.e. ith index -> ith deadline
        
        //getting maxdeadline
        int maxDead = INT_MIN;
        for(int i=0;i<n;i++) maxDead = max(maxDead,arr[i].dead);
        
        // initially all maxDead slots have no job assigned
        // keeping +1 to prevent array bound error
        vector<int> jobSchedule(maxDead+1,-1);
        
        // tend to do a job at the last day of its deadline so that
        // can perform other jobs on the rest of the days
        
        int totProfit = 0, totJobs = 0;
        
        // taking the largest profit job and try storing at last deadline day
        // of it, if slot filled try filling any of the previous empty days
        // keep iterating for all jobs going lesser and lesser profits as i
        // increases
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead-1;j>=0;j--){
                if(jobSchedule[j]==-1){
                    jobSchedule[j] = arr[i].id;
                    totProfit += arr[i].profit;
                    totJobs++;
                    break;
                }
            }
        }
        
        // jobSchedule contains all job id in sequence to be done
        
        // total jobs and total profit to be returned
        vector<int> ans = {totJobs,totProfit};
        return ans;
    } 
    
    
    
    
    
    
    
    // Method 2(understand method 1 first):
    // TC:O(nlogn) SC: O(maxDeadline)
    // for each job we get the latest empty slot in O(1)
    // thus total time to get the jobs is O(n),
    // the max time is taken to sort thus TC is O(nlogn)
    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr,arr+n,compare);
        
        int maxDead = INT_MIN;
        for(int i=0;i<n;i++) maxDead = max(maxDead,arr[i].dead);
        disjointSet ds(maxDead);
        
        int totProfit = 0, totJobs = 0;
        // vector to store the job sequence
        vector<int> jobSchedule;
        for(int i=0;i<n;i++){
            // get the latest empty slot
            int availableSlot = ds.findParent(arr[i].dead);
            
            // if the available slot is not 0(i indexed days) then we have
            // the empty slot else theres no slot for this job
            if(availableSlot>0){
                jobSchedule.push_back(arr[i].id);
                totProfit += arr[i].profit;
                totJobs++;
                // make the next empty slot as the available slot
                ds.Union(availableSlot);
            }
        }
        // jobSchedule contains all job id in sequence to be done
        
        // total jobs and total profit to be returned
        vector<int> ans = {totJobs,totProfit};
        return ans;
    }
};
