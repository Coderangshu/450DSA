// Can try making it faster
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> um;
        for(auto e:nums) um[e]++;
        vector<int> boxes;
        for(auto [_,f]:um) boxes.push_back(f);
        um.clear();
        sort(quantity.rbegin(),quantity.rend());
        dfs(boxes,quantity,0);
        return ans;
    }
    
    bool ans = false;
    
    void dfs(vector<int> &boxes, vector<int> &items, int ind){
        if(ind==items.size() or ans){
            ans = true;
            return;
        }
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]>=items[ind]){
                boxes[i] -= items[ind];
                dfs(boxes,items,ind+1);
                boxes[i] += items[ind];
            }
        }
    }
};