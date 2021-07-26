#include<bits/stdc++.h>
using namespace std;

// Method: Use stack and push all until closing bracket
// is found, when found pop all until openinig bracket is
// found pop the openinig too, then go on with the rest of
// the string.
// When we encounter a closing bracket check top if its
// closing bracket than we know that this is a redundant
// bracket, and we return true
// Else if after poping only one element we get '(' then
// also this is a redundant pair thus return true


bool checkRedundantBracks(string s){
	stack<char> stk;

	for(int i=0;i<s.length();i++){
		if(s[i]==')'){
			// if top is '(' means this pair
			// is a redundant pair
			if(stk.top()=='(') return true;

			// if after popping one element top
			// is '(' then also redundant pair
			stk.pop();
			if(stk.top()=='(') return true;

			// else pop until '(' reached
			while(stk.top()!='(') stk.pop();
			// pop '('
			stk.pop();
		}
		else stk.push(s[i]);
	}
	// reached here means no redundant pair found
	return false;
}

int main(){
	string s1 = "((a+b))";
	string s2 = "(a+(b)/c)";
	string s3 = "(a+b*(c-d))";

	cout<<checkRedundantBracks(s1)<<endl;
	cout<<checkRedundantBracks(s2)<<endl;
	cout<<checkRedundantBracks(s3)<<endl;

	return 0;
}
