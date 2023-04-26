#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Using Boyer Moore's Voting Algorithm
    // TC : O(nk)
    // SC : O(k)
    void moreThanNdK(vector<int> nums,int n,int k) {
        if(k<2) return;
        unordered_map<int,int> um;
        vector<int> ans;
        for(auto &e:nums){
            // if e found or still not found k elements put um[e] = 1
            if(um.count(e) or um.size()<k) um[e]++;
            // else we know element not in um and also um contains k elements
            // thus 2 options:
            // (1) if any element's frequency is 0 then replace with um[e] = 1
            // (2) else decrement every k element's frequency
            else{
                // finding element with frequency 1 (if any)
                int keyToRem;
                bool found = false;
                for(auto &[keyToRem,count]:um) if(count==0){
                    found = true;
                    break;
                }
                // if found replace with um[e] = 1
                if(found){
                    um.erase(keyToRem);
                    um[e]++;
                }
                // else decrement all frequencies
                else for(auto &[keyToRem,count]:um) count--;
            }
        }

        // check all candidates in um and insert to ans vector
        for(auto &[key,_]:um){
            int count = 0;
            for(auto &e:nums) if(e==key) count++;
            if(count>n/k) ans.push_back(key);
        }
        
        for(auto &e:ans) cout<<e<<" ";
        cout<<endl;
        return;
    }
};

int main()
{
	Solution obj;
    cout << "First Test\n";
    vector<int> arr1 = { 4, 5, 6, 7, 8, 4, 4 };
    int k = 3;
    obj.moreThanNdK(arr1, arr1.size(), k);

    cout << "\nSecond Test\n";
    vector<int> arr2 = { 4, 2, 2, 7 };
    k = 3;
    obj.moreThanNdK(arr2, arr2.size(), k);

    cout << "\nThird Test\n";
    vector<int> arr3 = { 2, 7, 2 };
    k = 2;
    obj.moreThanNdK(arr3, arr3.size(), k);

    cout << "\nFourth Test\n";
    vector<int> arr4 = { 2, 3, 3, 2 };
    k = 3;
    obj.moreThanNdK(arr4, arr4.size(), k);

    return 0;
}
