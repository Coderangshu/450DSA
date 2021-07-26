#include<bits/stdc++.h>
using namespace std;

// function to insert at bottom of stack
// this uses recursion to get the recursion
// stack to store the poped elements until
// s is empty then we insert the new element
// and then push the rest elements from the
// recursion stack

void insertAtBottom(stack<int> &s, int e){
	// base condition
	// if s is empty
	if(s.empty()) s.push(e);
	else{
		int f = s.top();
		s.pop();
		insertAtBottom(s,e);
		s.push(f);
	}
}

int main(){
	stack<int> s;
	for(int i=0;i<5;i++)
		insertAtBottom(s,i+1);

	for(int i=0;i<5;i++){
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
