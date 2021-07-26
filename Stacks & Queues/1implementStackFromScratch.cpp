#include<bits/stdc++.h>
using namespace std;

class Stack{
	private:
		int maxSize;
		int *stk;
		int top;
	public:
		Stack(int s){
			this->maxSize = s;
			this->stk = new int[s];
			this->top = -1;
		}
		
		void push(int e){
			this->stk[++this->top] = e;
		}

		int pop(){
			return this->stk[top--];
		}

		int peek(){
			return this->stk[top];
		}

		bool empty(){
			return (top==-1);
		}

		void clear(){
			this->top = -1;
		}

		int size(){
			return this->top+1;
		}
};

int main(){
	Stack s(5);
	s.push(1);
	s.push(3);
	cout<<"Size: "<<s.size()<<endl;
	s.push(12);
	cout<<"Size: "<<s.size()<<" Top: "<<s.peek()<<endl;
	cout<<"Is empty: "<<s.empty()<<endl;
	cout<<"Poped: "<<s.pop()<<endl;
	cout<<"Size: "<<s.size()<<endl;
	s.clear();
	cout<<"Size: "<<s.size()<<" Is empty: "<<s.empty()<<endl;
	return 0;
}
