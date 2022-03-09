// If a group of characters is interconnected by swap pairs, you can freely rearrange characters within that group.
// Thus join all pairs into a group then rearrange in sorted order
// Thus using disjoint set
class Solution {
private:
    int findParent(vector<int> &parent, int a){
        if(parent[a]==a) return a;
        return parent[a] = findParent(parent,parent[a]);
    }
    void Union(vector<int> &parent, vector<int> &height, int a, int b){
        int pa = findParent(parent,a), pb = findParent(parent,b);
        if(height[pa]<height[pb]) parent[pa] = pb;
        else if(height[pa]>height[pb]) parent[pb] = pa;
        else{
            parent[pb] = pa;
            height[pa]++;
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size(), np = pairs.size();
        
        vector<int> parent(n), height(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
        for(int i=0;i<np;i++) Union(parent,height,pairs[i][0],pairs[i][1]);
        
        unordered_map<int,vector<int>> um;
        for(int i=0;i<n;i++) um[findParent(parent,i)].push_back(i);
        
        for(auto &[_,p]:um){
            string tstring = "";
            for(auto &e:p) tstring += s[e];
            sort(tstring.begin(),tstring.end());
            sort(p.begin(),p.end());
            int i = 0;
            for(auto &e:p) s[e] = tstring[i++];
        }
        return s;
    }
};