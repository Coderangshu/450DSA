#include<bits/stdc++.h>
using namespace std;


// Naive method: take all letters after each letter and try by swapping
// T(n) : O((n^2)^k) 
// For every recursive call n^2 recursive calls is generated 
// until the value of k is 0. So total recursive calls are O((n^2)^k)

// recursive function to find max number with atmost
// k swaps
void findMaximum(string s, int k, string &ms){
	if(k==0) return;

	int n = s.length();

	// taking all the digits
	for(int i=0;i<n-1;i++){
		// compare with all the next digits
		for(int j=i+1;j<n;j++){
			// if digit at position i
            // is less than digit
            // at position j, swap it
            // and check for maximum
            // number so far and recurse
            // for remaining swaps
			if(s[i]<s[j]){
				swap(s[i],s[j]);
				// if current number is larger the max 
				// found till now
				if(s.compare(ms)>0) ms = s;
				// recurse for the next k-1 swaps
				findMaximum(s,k-1,ms);

				// Backtrack
				swap(s[i],s[j]);
			}
		}
	}
}



// Method: Find the greatest after each index and try out
// all its combinations and then send for the next index
// T(n) : O(n^k) 
// For every recursive call n recursive calls is generated 
// until the value of k is 0. So total recursive calls are O((n)^k).
class Solution
{
    private:
    void recursion(string &s, int ind, int k, string &ms){
        int n = s.length();
        if(k==0 or ind>=n) return;
        // Get the max char from ind+1 to last
        char mc = s[ind];
        for(int i=ind+1;i<n;i++) mc = max(mc,s[i]);
        // if no greater char found than move on to next index
        if(mc==s[ind]) recursion(s,ind+1,k,ms);
        // else try swapping the largest found at the last index as
        // this would yield the largest number in this swap
        else{
            for(int i=n-1;i>ind;i--){
                if(mc==s[i]){
                    swap(s[i],s[ind]);
                    if(s>ms) ms = s;
                    recursion(s,ind+1,k-1,ms);
                    swap(s[i],s[ind]);
                }
            }
        }
        return;
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ms = str;
       recursion(str,0,k,ms);
       return ms;
    }
};

int main(){
	string s = "129814999";
	int k = 4;

	string ms = s;
	findMaximum(s,0,k,ms);

	cout<<ms<<endl;
	return 0;
}

