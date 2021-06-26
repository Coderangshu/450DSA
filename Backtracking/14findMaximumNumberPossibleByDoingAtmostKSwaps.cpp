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

// NOTE: Keep in mind the k decremtation its tricky as for some 
// arrangements the k doesnt completes its last swap


void findMaximum(string s, int index, int k, string &ms){
	int n = s.length();
    
	if(k==0 or index==n) return;

    // finding the largest number in the given string
    char mc = s[index];
    for(int i=index+1;i<n;i++)
        if(s[i]>mc) mc = s[i];
    
    // if greater number than that in index is found after the index
    // then there will be a swap surely, so decrementing k
    if(mc!=s[index]) k--;
    
    // if char greater than s[index] found then we swap
    // and find further
    // search maximum in the indexes after index
    for(int i=index;i<n;i++){
        // if found swap with char at index
        if(s[i]==mc){
            swap(s[index],s[i]);
            // if current formed number is larger the 
            // max found till now
            if(s.compare(ms)>0) ms = s;
            // recurse for the next k swaps
            findMaximum(s,index+1,k,ms);
                
            // Backtrack
            swap(s[index],s[i]);
        }
    }
    return;
}

int main(){
	string s = "129814999";
	int k = 4;

	string ms = s;
	findMaximum(s,0,k,ms);

	cout<<ms<<endl;
	return 0;
}

