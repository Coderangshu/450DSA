class Solution {
public:
    
    
    
    // Method 1:
    // TC: O(n), SC: O(n)
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        // storing cumulative number of 1s upto ith index
        vector<int> countOnes(n);
        int i = 0, cumCntOne = 0;
        for(auto c:s){
            if(c=='1') countOnes[i++] = ++cumCntOne;
            if(c=='0') countOnes[i++] = cumCntOne;
        }
        
        // taking all partitions whose left all should be 0 and
        // right all one, to do so min flips will be the answer
        // initially countFlips stores when partition is at -1
        // i.e. all should be 1 in string
        int countFlips = n-countOnes[n-1];
        for(i=0;i<n;i++){
            countFlips = min(countFlips,countOnes[i]+((n-1)-i-(countOnes[n-1]-countOnes[i])));
        }
        return countFlips;
    }
    
    
    
    
    // Method 2:
    // TC: O(n), SC: O(1)
    int minFlipsMonoIncr1(string s) {
        // at any point of string, if 1 comes monotonicity continues
        // if 0 comes we got 2 choices either flip this 0 or flip
        // all the previous 1s to 0
        int countFlip = 0, countOne = 0;
        for(auto c:s){
            if(c=='0') countFlip = min(countFlip+1,countOne);
            if(c=='1') countOne++;
        }
        return countFlip;
    }
};
