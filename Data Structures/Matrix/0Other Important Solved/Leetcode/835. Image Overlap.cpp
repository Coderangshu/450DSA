// Question : https://leetcode.com/problems/image-overlap/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        unordered_map<string,int> um;
        int n = img1.size();
        vector<pair<int,int>> a1, a2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]) a1.push_back({i,j});
                if(img2[i][j]) a2.push_back({i,j});
            }
        }
        // creating vector with all point pairs and tracking count of each of those vectors 
        for(int i=0;i<size(a1);i++){
            for(int j=0;j<size(a2);j++){
                string key = to_string(a1[i].first-a2[j].first)+" "+to_string(a1[i].second-a2[j].second);
                um[key]++;
            }
        }
        // return the highest count vector
        int ans = 0;
        for(auto &[_,freq]:um) ans = max(ans,freq);
        return ans;
    }
};