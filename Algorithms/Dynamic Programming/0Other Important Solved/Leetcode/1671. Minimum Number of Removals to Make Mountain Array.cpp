class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // find the lis from left to right and right to left
        // for each i index keep track of the length of the lis
        // formed upto that index, for both left to right and right
        // to left.
        // To get the answer we check for all the i indices, wherever
        // both l->r and r-> LISs lengths are > 1, we try updating
        // the answer to get the min # of deletions required
        
        int n = nums.size();
	// the max deletion possible is the complete nums array
        int ans = n;

        vector<int> l, r, sizeLISUptoIth;

	// getting the lis and the length of lis upto ith index
	// in sizeLISUptoIth from left -> right 
        for(int i=0;i<n;i++){
            if(l.empty() or l.back()<nums[i]) l.push_back(nums[i]);
            else{
                auto it = lower_bound(l.begin(),l.end(),nums[i]);
                *it = nums[i];
            }
            sizeLISUptoIth.push_back(l.size());
        }
        
	// getting the lis and calculating the min deletions on the fly
	// by getting the lis length upto ith index from left to right
	// from the sizeLISUptoIth and getting the size directly from the
	// lis from right to left upto index i 
        for(int i=n-1;i>=0;i--){
            if(r.empty() or r.back()<nums[i]) r.push_back(nums[i]);
            else{
                auto it = lower_bound(r.begin(),r.end(),nums[i]);
                *it = nums[i];
            }
            int rsize = r.size();
            if(sizeLISUptoIth[i]>1 and rsize>1){
                ans = min(ans,n-(sizeLISUptoIth[i]+rsize)+1);
            }
        }
        return ans;
    }
};
