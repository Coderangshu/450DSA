#include<bits/stdc++.h>
using namespace std;

// we use insert at bottom to reverse the stack

void insertAtBottom(stack<int> &s, int e){
	if(s.empty()) s.push(e);
	else{
		int f = s.top();
		s.pop();
		insertAtBottom(s,e);
		s.push(f);
	}
}

void reverse(stack<int> &s){
	if(!s.empty()){
		// storing from top to bottom
		// in recursion stack
		int e = s.top();
		s.pop();
		reverse(s);

		// insert the elements from
		// recursion stack bottom to top
		insertAtBottom(s,e);
	}
}

int main(){
	stack<int> s;
	for(int i=1;i<=5;i++) s.push(i);
	cout<<"Original Stack(top->bottom): 5 4 3 2 1"<<endl;

	// reversing s
	reverse(s);
	cout<<"Reversed Stack(top->bottom): ";
	for(int i=0;i<5;i++){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}
