#include<bits/stdc++.h>
using namespace std;

// have to use only 1 stack

// Example : Q = 1 2 3 4 5 6 7 8 9 10, S = empty(top->bottom)
// (1) Dequeue and push first half
//			Q = 6 7 8 9 10, S = 5 4 3 2 1

// (2) Pop and enqueue
//			Q = 6 7 8 9 10 5 4 3 2 1, S = empty

// (3) Dequeue and enqueue first half
//			Q = 5 4 3 2 1 6 7 8 9 10, S = empty

// (4) Dequeue and push first half
//			Q = 6 7 8 9 10, S = 1 2 3 4 5

// (5) Interleave->(pop-enqueue-dequeue-enqueue)x(n/2) times
//		After 1st cycle: Q = 7 8 9 10 1 6, S = 2 3 4 5
//		After 2nd cycle: Q = 8 9 10 1 6 2 7, S = 3 4 5
//		After 3rd cycle: Q = 9 10 1 6 2 7 3 8, S = 4 5
//		After 4th cycle: Q = 10 1 6 2 7 3 8 5 9, S = 5
//		After 5th cycle: Q = 1 6 2 7 3 8 5 9 5 10, S = empty

void interleaveQueue(queue<int>&q){
	stack<int> s;
	int nh = q.size()/2;

	// Step 1:
	for(int i=0;i<nh;i++){
		s.push(q.front());
		q.pop();

	}

	// Step 2:
	for(int i=0;i<nh;i++){
		q.push(s.top());
		s.pop();
	}

	// Step 3:
	for(int i=0;i<nh;i++){
		q.push(q.front());
		q.pop();
	}

	//Step 4:
	for(int i=0;i<nh;i++){
		s.push(q.front());
		q.pop();
	}

	// Step 5:
	while(!s.empty()){
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
}

int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	q.push(10);

	interleaveQueue(q);

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}
