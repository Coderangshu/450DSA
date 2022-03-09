// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		for(int i=0;i<n;i++){
//             cout<<s.top()<<endl;
//             s.pop();
            cout<<getMin(s)<<" "<<pop(s)<<" "<<getMin(s)<<endl;
        }
// 		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends



// Using O(n) space we can implement to get min in O(1)
// we use auxilary stack to keep track of the min upto current
// element, example:
// let question pushes into stack: 8 10 6 3 7
// auxilary stack we push for each entry:
// for 8 push 8
// for 10 push 8
// for 6 push 6
// for 3 push 3
// for 7 push 3
// thus auxilary stack contains: 8 8 6 3 3
// when we pop from main stack we also pop from auxilary stack
// to keep the min element upto the current top of main stack



// Using O(1) space in O(1) time also we can get the min
// here we modify the input numbers into the main stack
// and maintain a min variable that stores the min upto the
// top of the stack.
// Whenever we get a new min then we use the below formulae
// to modify the current element and update the new min
// in the min variable
// Formulae : diff = 2*e-min, where e is element to be pushed
// actually the above is the difference of e and min
// but as e is small we multiply by 2 and then find
// difference, min>e thus 2e-min will be less than e
// now while popping Whenever less than min will be detected
// that will indicate that the top has been modified

// now the element in stack stores the previous
// min info in itself and the new min is updated
// for popping until greater than min is in stack
// pop, when lesser than min then return the current
// min and than update the min for the previous
// elements
// to get the previous min use formulae: e = 2*min-diff,
// where e is the new min of the left over stack

int Min;

void push(stack<int>& s, int a){
	// Your code goes here

	// if stack is empty then this is
	// the min element
	if(s.empty()){
	    Min = a;
	    s.push(a);
	}
	else{
	    // if new min found
	    if(a<Min){
	        // push modified a in stack which
	        // preserves the info about the
	        // previous min
	        s.push(2*a-Min);
	        // update new min
	        Min = a;
	    }
	    else s.push(a);
	}
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return (s.size()==n);
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return (s.size()==0);
}

int pop(stack<int>& s){
	// Your code goes here

	// to store the item poped
	int item;
	// if s.top is greater than equal to
    // min than no problem return as it is
	if(s.top()>=Min){
	    item = s.top();
	    s.pop();
	}
	else{
	    // we know the min is the actual s.top()
	    // now we need to modify the s.top() to get
	    // the previously stored prev min in it
	    item = Min;
	    Min = 2*Min-s.top();
	    s.pop();
	}
	return item;
}

int getMin(stack<int>& s){
	// Your code goes here
	return Min;
}
