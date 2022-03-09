// Question : https://leetcode.com/problems/range-sum-query-mutable/
// Included the range update (incrementing) using lazy propagation method (not part of above question)
#include<bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> nums, segmentTree, lazyPropagate;
    int n;
    
    void buildTree(int ind, int start, int end){
        if(start==end) segmentTree[ind] = nums[start];
        else{
            int mid = (start+end)>>1;
            buildTree(2*ind+1,start,mid);
            buildTree(2*ind+2,mid+1,end);
            segmentTree[ind] = segmentTree[2*ind+1]+segmentTree[2*ind+2];
        }
        return;
    }
    
    // left and right ---> given range
    // start and end ---> range of current segment
    int getSum(int ind, int left, int right, int start, int end){
        // segment tree segment lies completely inside given range (total overlap)
        if(left<=start and end<=right) return segmentTree[ind];
        
        // segment tree segment lies completely outside given range (no overlap)
        else if(end<left or right<start) return 0;
        
        // segment tree segment lies partially inside given range (partial overlap)
        else{
            int mid = (start+end)>>1;
            return getSum(2*ind+1,left,right,start,mid) +
                   getSum(2*ind+2,left,right,mid+1,end);
        }
    }
    
    void pointUpdate(int ind, int index, int val, int start, int end){
        if(start==index and index==end) segmentTree[ind] = val;
        else{
            int mid = (start+end)>>1;
            if(index<=mid) pointUpdate(2*ind+1,index,val,start,mid);
            else pointUpdate(2*ind+2,index,val,mid+1,end);
            segmentTree[ind] = segmentTree[2*ind+1]+segmentTree[2*ind+2];
        }
        return;
    }

    void rangeIncrementUpdate(int ind, int left, int right, int val, int start, int end){
        // update sum with values left to be updated from lazy propagate
        if(lazyPropagate[ind]!=0){
            segmentTree[ind] += (end-start+1)*lazyPropagate[ind];
            if(start!=end){
                lazyPropagate[2*ind+1] += lazyPropagate[ind];
                lazyPropagate[2*ind+2] += lazyPropagate[ind];
            }
            lazyPropagate[ind] = 0;
        }
        
        // no overlap
        if(right<start or end<left) return;
        
        // total overlap
        if(left<=start and end<=right){
            segmentTree[ind] += (end-start+1)*val;
            if(start!=end){
                lazyPropagate[2*ind+1] += val;
                lazyPropagate[2*ind+2] += val;
            }
            return;
        }
        
        // partial overlap
        int mid = (start+end)>>1;
        rangeIncrementUpdate(2*ind+1,left,right,val,start,mid);
        rangeIncrementUpdate(2*ind+2,left,right,val,mid+1,end);
        segmentTree[ind] = segmentTree[2*ind+1]+segmentTree[2*ind+2];
        return;
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        segmentTree.resize(4*n);
        lazyPropagate.assign(4*n,0);
        buildTree(0,0,n-1);
    }
    
    void update(int index, int val) {
        pointUpdate(0,index,val,0,n-1);
    }
    
    void rangeIncrement(int left, int right, int val) {
        rangeIncrementUpdate(0,left,right,val,0,n-1);
    }

    int sumRange(int left, int right) {
        return getSum(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

 int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    NumArray* obj = new NumArray(nums);
    while(true){
        string s;
        cin>>s;
        if(s=="q") break;
        else if(s=="s"){
            int l,r;
            cin>>l>>r;
            cout<<obj->sumRange(l,r)<<endl;
        }
        else if(s=="u"){
            int i;
            cin>>i;
            if(i<0 or i>n-1) cout<<"Invalid index"<<endl;
            else{
                int val;
                cin>>val;
                obj->update(i,val);
            }
        }
        else{
            int l,r;
            cin>>l>>r;
            if(l<0 or l>n-1 or r<0 or r>n-1) cout<<"Invalid index"<<endl;
            else{
                int val;
                cin>>val;
                obj->rangeIncrement(l,r,val);
            }
        }
    }
    return 0;
 }