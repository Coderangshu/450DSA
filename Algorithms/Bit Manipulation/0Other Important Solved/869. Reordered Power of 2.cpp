// https://leetcode.com/problems/reordered-power-of-2/
// Kind of bit manipulation thus putting up here
// constraint n<10^9
// for n>10^9 use unordered_map instead of freqNum

class Solution {
private:
    // function converts as shown in example below
    // 347322 => 10012200
    // implying 1 7, 1 4, 2 3s and 2 2s
    // like an frequency array of digits but 
    //constructed in a number where position denotes
    // the digit and the number at that position
    // denotes the freq of that digit in the number n
    int convertToFreqNum(int n){
        int res = 0;
        for(;n>0;n/=10) res += pow(10,n%10);
        return res;
    }
public:
    bool reorderedPowerOf2(int n) {
        int freqNum = convertToFreqNum(n);
        // compare this freqNum to all powers of 2's freqNum
        for(int i=0;i<32;i++) if(freqNum==convertToFreqNum(1<<i))
            return true;
        return false;
    }
};