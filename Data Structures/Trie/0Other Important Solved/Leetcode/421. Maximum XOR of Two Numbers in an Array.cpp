struct trieNode{
    trieNode* children[2] = {nullptr,nullptr};
};

class Solution {
private:
    void insert(trieNode *root, int num){
        auto cur = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!cur->children[bit]) cur->children[bit] = new trieNode();
            cur = cur->children[bit];
        }
    }
    
    int getMax(trieNode *root, int number){
        auto cur = root;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int requiredBit = !(number&(1<<i));
            if(cur->children[requiredBit]){
                ans |= (1<<i);
                cur = cur->children[requiredBit];
            }
            else cur = cur->children[!requiredBit];
        }
        return ans;
    }
    
    // using trie to store the bitwise representation
    // of all the # in nums, MSB to LSB from top to bottom
    // then using each # from nums, we try get the requiredBit
    // which if found is taken into answer else we move on to that
    // bit without adding it into our result, thus as we take from
    // MSB to LSB we get the largest XOR pair for that particular #.
    // This way continue to find for all #s of nums and return the max
    // Getting max for each # is taking O(n) time (searching time in trie)
    // thus overall TC is O(32n)
    int usingTrie(vector<int> &nums){
        trieNode *root = new trieNode();
        for(auto &e:nums) insert(root,e);
        int ans = 0;
        for(auto &e:nums) ans = max(ans,getMax(root,e));
        return ans;
    }
    
    // More intuitive method using hashmap
    // this approach TC is O(32n) but it works in much
    // lesser time, as set won't contain all # of nums
    // at every iteration as there would be same # and we
    // know set doesn't add repeting elements
    int usingHashmap(vector<int> &nums){
        int ans = 0, mask = 0;
        // traversing once from MSB to LSB
        for(int i=31;i>=0;i--){
            // mask will add 1 from MSB to LSB in each iteration
            // 100..000 -> 110..000 -> 111..000 -> so on.... 32 times
            mask |= 1<<i;
            // storing the MSBs of each # in nums upto where the mask is on
            unordered_set<int> us;
            for(auto &e:nums) us.insert(e&mask);
            // considering our ans as previous max ans found with
            // ith bit turned on (which is larger than the previous
            // max ans)
            int tempAns = ans | (1<<i);
            // required to be answer is tempAns, so if we find
            // int the set for each # in set if found a 
            // tempAns^(that #) than we can say that tempAns
            // can be formed by (that #)^(the one found),
            // thus we can say that tempAns can be formed and thus
            // make it our new max ans, we do this for all # in set
            for(auto &e:us) if(us.find(e^tempAns)!=us.end()){
                ans = tempAns;
                break;
            }
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        // return usingTrie(nums);
        return usingHashmap(nums);
    }
};