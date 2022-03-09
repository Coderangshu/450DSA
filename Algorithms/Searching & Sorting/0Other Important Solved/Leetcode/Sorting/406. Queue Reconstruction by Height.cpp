// Question : https://leetcode.com/problems/queue-reconstruction-by-height/

// 2 ways of doing


// First method: 
// 1. arrange in decreasing order of height, when height same in increasing order of k
// 2. insert each in their respective kth position

// As inserting the largest heights first, this ensures that largest height stays at beginning
// but for the k we need to keep the smallest k at first thus the sorting is done in increasing
// order of k when height is same, now while inserting we know the current element to be
// inserted is smaller or equal to the element at k, thus we do 1 right shift on all those
// elements and place the current element at its kth position

// Second method:
// 1. arrange in increasing order of height, when height same in decreasing order of k
// 2. insert elements in their kth place, we find the kth position w.r.t. the empty spaces

// Here we insert the greater k valued person first as we are inserting w.r.t. the empty spaces
// we know that the new element to be inserted is greater or equal thus it would be inserted
// in index less that the other equal height person already insert if present

// Both approach takes O(n^2) TC
// the 2nd approach can be done in O(nlogn) using Binary Indexed Tree

class Solution {
private:
    vector<vector<int>> method1(vector<vector<int>>& p){
        sort(p.begin(),p.end(),[](vector<int>&a, vector<int>&b){
            if(a[0]!=b[0]) return a[0]>b[0];
            else return a[1]<b[1];
        });
        
        vector<vector<int>> ans;
        for(auto &e:p) ans.insert(ans.begin()+e[1],e);
        return ans;
    }
    
    vector<vector<int>> method2(vector<vector<int>> &p){
        sort(p.begin(),p.end(),[](vector<int>&a, vector<int>&b){
            if(a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
        });
        
        int n = p.size();
        vector<vector<int>> ans(n,vector<int>(0));
        for(auto &e:p){
            int emptySpaceCnt = 0, i = 0;
            for(;i<n;i++){
                if(ans[i].size()==0){
                    if(emptySpaceCnt==e[1]) break;
                    emptySpaceCnt++;
                }
            }
            ans[i] = e;
        }
        return ans;
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        return method1(people);
        // return method2(people);
    }
};