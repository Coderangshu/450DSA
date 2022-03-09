// 5 methods brute force to most optimized

// check all substrings
// TC : O(n^3)
// SC : O(1)
class Solution{
    private:
    bool isPalindrome(const string &s, int i, int j){
        while(i<j) if(s[i++]!=s[j--]) return false;
        return true;
    }
    public:
    string longestPalindrome(string s) {
        int startInd, maxLen = INT_MIN, n = s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(j-i+1>maxLen and isPalindrome(s,i,j)){
                    startInd = i;
                    maxLen = j-i+1;
                }
            }
        }
        return s.substr(startInd,maxLen);
    }
};


// binary searching over length twice (odd and even seperately)
// TC : O(n^2*logn)
// SC :O(1)
class Solution{
    private:
    bool isPalindrome(const string &s, int i, int j){
        while(i<j) if(s[i++]!=s[j--]) return false;
        return true;
    }
    int thereExistOfLengthMid(const string &s, int n, int mid){
        for(int i=0;i<n-mid+1;i++){
            if(isPalindrome(s,i,i+mid-1)) return i;
        }
        return -1;
    }
    public:
    string longestPalindrome(string s) {
        int startInd, maxLen = INT_MIN, n = s.length();
        // binary searching over lengths for odd lengths ones and even lengths ones
        // binary searching because if palindrome of length 5 is found then
        // there will exist a palindrome of length 3 and 1 too, same for even
        // lengths. Thus we continue searching for longer lengths.
        for(int parity:{0,1}){
            int low = 1, high = n;
            if(low%2!=parity) low++;
            if(high%2!=parity) high--;
            while(low<=high){
                int mid = (low+high)>>1;
                if(mid%2!=parity) mid++;
                if(mid>high) break;
                int temp = thereExistOfLengthMid(s,n,mid);
                if(temp!=-1){
                    if(mid>maxLen){
                        maxLen = mid;
                        startInd = temp;
                    }
                    low = mid+2;
                }
                else high = mid-2;
            }
        }
        return s.substr(startInd,maxLen);
    }
};

// checking for all substrings of each length from 1 -> n
// TC : O(n^2)
// SC : O(n^2)
class Solution {
    public:
    string longestPalindrome(string s) {
        int n = s.length(), startInd, maxLen = INT_MIN;
        vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
        // iterating over lengths i to n
        for(int l=1;l<=n;l++){
            // taking all substring of length l
            for(int i=0;i<n-l+1;i++){
                int j = i+l-1;
                if(l==1){
                    isPalindrome[i][j] = true;
                    if(maxLen<l){
                        startInd = i;
                        maxLen = l;
                    }
                }
                else if(s[i]==s[j] and (l==2 or isPalindrome[i+1][j-1])){
                    isPalindrome[i][j] = true;
                    if(maxLen<l){
                        startInd = i;
                        maxLen = l;
                    }
                }
            }
        }
        return s.substr(startInd,maxLen);
    }
};

// taking each char as mid and expanding equally on both sides
// ones for odd length (mid being a char) and even length (mid being mid of char)
// TC : O(n^2)
// SC : O(1)
class Solution{
    public:
    string longestPalindrome(string s) {
        int n = s.length(), startInd, maxLen = INT_MIN;
        // odd lengths
        for(int i=0;i<n;i++){
            for(int j=0;i-j>=0 and i+j<n;j++){
                if(j!=0 and s[i-j]!=s[i+j]) break;
                if(2*j+1>maxLen){
                    maxLen = 2*j+1;
                    startInd = i-j;
                }
            }
        }
        // even lengths
        for(int i=0;i<n;i++){
            for(int j=1;i-j>=0 and i+j-1<n;j++){
                if(s[i-j]!=s[i+j-1]) break;
                if(2*j>maxLen){
                    maxLen = 2*j;
                    startInd = i-j;
                }
            }
        }
        return s.substr(startInd,maxLen);
    }
};

// Manacher's Algorithm
// Video explanation : https://youtu.be/kbUiR5YWUpQ
// Similar concept as above just using the left calculated
// lengths from mid to fill the right ones and expanding if
// possible
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
};