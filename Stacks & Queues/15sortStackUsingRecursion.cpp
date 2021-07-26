#include<bits/stdc++.h>
using namespace std;

void sortNInsert(stack<int> &s, int e){
	if(s.empty() or s.top()<e) s.push(e);
	else{
		int f = s.top();
		s.pop();
		sortNInsert(s,e);
		s.push(f);
	}
}

void sortStack(stack<int> &s){
	if(!s.empty()){
		int e = s.top();
		s.pop();
		sortStack(s);
		sortNInsert(s,e);
	}
}

int main(){
	stack<int> s;
	s.push(34);
	s.push(23);
	s.push(89);
	s.push(56);
	s.push(65);
	s.push(12);
	cout<<"Unsorted stack(top->bottom): 12 65 56 89 23 34\n";

	sortStack(s);
	cout<<"Sorted stack(top->bottom): ";
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
	return 0;
}









// GFG practice code

// { Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;
//
// class SortedStack{
// public:
// 	stack<int> s;
// 	void sort();
// };
//
// void printStack(stack<int> s)
// {
//     while (!s.empty())
//     {
//         printf("%d ", s.top());
//        	s.pop();
//     }
//     printf("\n");
// }
//
// int main()
// {
// int t;
// cin>>t;
// while(t--)
// {
// 	SortedStack *ss = new SortedStack();
// 	int n;
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{
// 	int k;
// 	cin>>k;
// 	ss->s.push(k);
// 	}
// 	ss->sort();
// 	printStack(ss->s);
// }
// }// } Driver Code Ends
//
//
//
//
// Funtion to sort and insert elements in stack
//
// void sortNInsert(stack<int> &s, int e){
//     as we arrange in descending order from top to
//     bottom thus if s is empty or s.top() is smaller
//     than we push e
//     if(s.empty() or s.top()<e)
//         s.push(e);
//     else we pop sort and push e into leftover stack
//     then push the previous top to keep it at the top
//     as that is the largest element
//     else{
//         int f = s.top();
//         s.pop();
//         sortNInsert(s,e);
//         s.push(f);
//     }
// }
//
//
// /* The below method sorts the stack s
// you are required to complete the below method */
//
// void SortedStack :: sort()
// {
//    Your code here
//    store all elements in recursion stack
//    sort the smaller stack then push the
//    element from recursion stack
//    if(!SortedStack :: s.empty()){
//        int e = SortedStack :: s.top();
//        SortedStack :: s.pop();
//        SortedStack :: sort();
//        sortNInsert(s,e);
//    }
// }
