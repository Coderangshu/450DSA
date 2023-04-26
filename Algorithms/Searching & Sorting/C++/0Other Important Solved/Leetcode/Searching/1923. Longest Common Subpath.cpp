class Solution {
 private:
    // function to find if len length path is common in all the paths
    // with the help of Rabin-Karp subsequence finding algorithm with
    // collision checking
    bool thisLengthIsCommon(int len, vector<vector<int>>& paths){
        // to store the {hash,begining index of the matching paths in vector} pairs
        unordered_map<long long int,vector<int>> um;
        long long int mul = 1e5+1, mod = 1e11+7;
        // if in some point um becomes empty we stop loop as there's no common path
        // existing upto that index thus no reason of checking further
        for(int i=0;i<paths.size() and (i==0 or !um.empty());i++){
            long long int hash = 0, d = 1;
            unordered_map<long long int,vector<int>> tempUm;
            for(int j=0;j<paths[i].size();j++){
                hash = (hash*mul+paths[i][j])%mod;
                if(j<len) d = (d*mul)%mod;
                else hash = (mod+hash-(d*paths[i][j-len])%mod)%mod;
                if(j>=len-1){
                    // if checking 1st path inserting all hashes of length len
                    if(i==0) tempUm[hash].push_back(j-(len-1));
                    // else we check if current hash path was found previously
                    // if found then go through each begining positions stored
                    // int um, and check each path if found common add this index
                    // to the tempUm and break as we need just 1 common path
                    else{
                        if(um.count(hash))
                            for(auto &b:um[hash])
                                if(equal(begin(paths[0])+b,begin(paths[0])+b+len,
                                         begin(paths[i])-(len-1)+j)){
                                    tempUm[hash].push_back(b);
                                    break;
                                }
                    }
                }
            }
            // Swapping instead of assigning as assigning makes a copy and then
            // assigns that copy the given name, but swapping occurs on the memory
            // address that happens instantaneously 
            swap(um,tempUm);
        }
        // if um's empty means no common path exist of length len
        return um.empty()?false:true;
    }
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        // low can be 0, high can be atmost the min length path of all
        int low = 0;
        int high = min_element(begin(paths),end(paths),[&](const auto &a, const auto &b){
                       return a.size()<b.size();
                   })->size();
        int ans = -1;
        while(low<=high){
            int mid = (low+high+1)>>1;
            if(thisLengthIsCommon(mid, paths)) ans = mid, low = mid+1;
            else high = mid-1;
        }
        return ans;
    }
};