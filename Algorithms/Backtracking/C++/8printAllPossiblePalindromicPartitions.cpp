#include<bits/stdc++.h>
using namespace std;

// function to check is a word is palindrome
bool isPalindrome(string s, int begin, int end){
	while(begin<end){
		if(s[begin]!=s[end]) return false;
		begin++;
		end--;
	}
	return true;
}

// recursive function to find all possible palindromic partition of given string
void getAllPartitions(string s,  vector<vector<string>> &app, vector<string> &cp, int start, int len){
	// base condition
	// if start has reached the length of given string means
	// the complete string has been traversed
	if(start>=len){
		app.push_back(cp);
		return;
	}

	// get all possible substrings for the current string
	for(int i=start;i<len;i++){
		// if the substring obtained is palindrome
		if(isPalindrome(s,start,i)){
			// push the substring into the current string vector
			// as this will be a palindrome substring of the current
			// input string s 
			cp.push_back(s.substr(start,i-start+1));
			// send the other substring to be checked and inserted
			// into current string vector
			getAllPartitions(s,app,cp,i+1,len);
			// pop the last added palindrome to reach the position
			// where the loop was started (BACKTRACK) to try out and
			// store the next possible substrings
			cp.pop_back();
		}
	}
	return;
}

// Same as above
class Solution {
private:
    
    bool isPalindrome(string &s){
        int b = 0, e = s.length()-1;
        while(b<e) if(s[b++]!=s[e--]) return false;
        return true;
    }

    void recursion(const string &s, vector<vector<string>> &ans, vector<string> t, int i){
        int n = s.length();
        if(i>=n) ans.push_back(t);
        else{
            for(int len=1;len<=n-i;len++){
                string ns = s.substr(i,len);
                if(isPalindrome(ns)){
                    t.push_back(ns);
                    recursion(s,ans,t,i+len);
                    t.pop_back();
                }
            }
        }
        return;
    }
public:
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        vector<string> t;
        recursion(S,ans,t,0);
        return ans;
    }
};

int main(){
	string s = "malayalam";

	// to store all the palindromic partitions
	vector<vector<string>> allPalindromicParts;

	// to store current palindromic partition
	vector<string> currentPartition;

	getAllPartitions(s,allPalindromicParts,currentPartition,0,s.length());

	for(auto cp:allPalindromicParts){
		for(auto word:cp) cout<<word<<" ";
		cout<<endl;
	}
	return 0;
}
