// Related to various problems based on Palindromic Substrings

// Video explanation : https://youtu.be/kbUiR5YWUpQ

// taking each char as mid and expanding equally on both sides
// introducing '#' in between each character to calculate palindromes
// for even lengths, to reduce TC using the left calculated lengths from
// mid to fill the right ones and expanding if possible
// TC : O(n)
// SC : O(2n)
class Solution {
    private:
    string preprocess(const string &s){
        string ans = "#";
        for(auto e:s){
            ans += e;
            ans += '#';
        }
        return ans;
    }
    public:




    // Find longest palindromic substring
    string longestPalindrome(string s) {
        // let sample string = babad
        // converting with hashes in mid to
        // get both odd and even length palidromes
        // i.e. #b#a#b#a#d#
        string modStr = preprocess(s);
        // c = center of palidrome
        // r = right end of palindrome
        int c = 0, r = 0, n = modStr.length(), ansMid, maxLen = INT_MIN;
        // store the max length of palindrome from current mid both side
        // forming a palindrome
        // for above modStr -> # b # a # b # a # d #
        //                     0 1 0 3 0 3 0 1 0 1 0
        // from # can extend upto 0 length on both side to get a palindrome "#""
        // from b can extend upto 1 length on both side to get a palindrome "#b#"
        // from # can extend upto 0 length on both side to get a palindrome "#"
        // from a can extend upto 3 length on both side to get a palindrome "#b#a#b#"
        // from # can extend upto 0 length on both side to get a palindrome "#"
        // from b can extend upto 3 length on both side to get a palindrome "#a#b#a#"
        // from # can extend upto 0 length on both side to get a palindrome "#"
        // from a can extend upto 1 length on both side to get a palindrome "#a#"
        // from # can extend upto 0 length on both side to get a palindrome "#"
        // from d can extend upto 1 length on both side to get a palindrome "#d#"
        // from # can extend upto 0 length on both side to get a palindrome "#"

        // initially all length can be extended upto 0 size
        vector<int> p(n,0);
        // considering each index as mid
        for(int i=0;i<n;i++){
            // getting left index w.r.t c as mirror of current index
            int l = c-(i-c);
            
            // if mid is lower than r means its part of current palindrome
            // thus length with this as mid would be min of left part's length
            // and length from mid to right boundary of current palindrome 
            // as right boundary is upto which we have information
            if(i<r) p[i] = min(p[l],r-i);

            // extending on both size w.r.t. mid starting from length p[i] as upto this
            // length we know its a palindrome length to check if palindrome forms or not
            while(i+(p[i]+1)<n and i-(p[i]+1)>=0 and modStr[i+(p[i]+1)]==modStr[i-(p[i]+1)]) p[i]++;

            // if right boundary of palindrome w.r.t. current mid is more than current right boundary
            // update the center to this mid and r to this right boundary
            if(i+p[i]>r){
                c = i;
                r = i+p[i];
            }
            
            // getting the mid and length for the largest palindrome discovered till now
            if(p[i]>maxLen){
                ansMid = i;
                maxLen = p[i];
            }
        }
        // extracting the answer from modStr
        string ans = "", tans = "";
        for(int j=ansMid-maxLen;j<=ansMid+maxLen;j++) tans += modStr[j];
        for(auto e:tans) if(e!='#') ans += e;
        return ans;
    }




    // Count total palindromic substrings
    int countSubstrings(string s) {
        string t = preprocess(s);
        int n = t.length(), c = 0, r = 0;

        // sl -> semiLength
        vector<int> sl(n,0);
        for(int i=0;i<n;i++){
            int l = c-(i-c);
            if(i<r) sl[i] = min(sl[l],r-i);
            while(i-(sl[i]+1)>=0 and i+(sl[i]+1)<n and t[i-(sl[i]+1)]==t[i+(sl[i]+1)]) sl[i]++;
            if(i+sl[i]>r){
                c = i;
                r = i+sl[i];
            }
        }
        
        int ans = 0;
        for(int &e:sl) ans += (e+1)/2;
        return ans;
    }
};