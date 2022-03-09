// If unable to understand go through this :
// https://www.youtube.com/watch?v=S5cYO9k1Ja8


#include<bits/stdc++.h>
using namespace std;

class kStacks{
	private:
		// single array to store the elements
		// of k stacks
		int *arr;
		// to store the top of eack of k stacks
		// size of this is k
		int *top;
		// next serves 2 purposes when a cell in 
		// arr is empty then the corresponding
		// index in next contains the next cell
		// that is available after filling this
		// current cell,
		// the other purpose is when cell in arr
		// is filled then the corresponding index
		// in the next gives us the index of the
		// previous element of that stack (the next
		// of the top)
		int *next;
		// to store the next free slot in arr
		int freeSlot;
		int n,k;

	public:
		// constructor
		kStacks(int N, int K){
			this->n = n;
			this->k = k;
			this->arr = new int[N];
			this->top = new int[K];
			this->next = new int[N];

			// initializing all stacks as empty
			for(int i=0;i<K;i++) top[i] = -1;

			// initializing freeSlot as the 1st
			// empty cell in arr
			this->freeSlot = 0;

			// initializing the next empty slots
			// for each index in arr
			for(int i=0;i<N-1;i++) next[i] = i+1;
			// for the last index of arr there's no
			// next empty slot so putting -1
			next[N-1] = -1;
		}

		// pushing into given stack
		void push(int e, int stkNum){
			if(this->freeSlot==-1){
				cout<<"Stack Overflow"<<endl;
				return;
			}

			// where to store e in arr
			int i = freeSlot;

			// update freeSlot to next freeSlot
			this->freeSlot = this->next[i];
			
			// as now i will be filled up so next will
			// point to the previous top of this stack
			this->next[i] = this->top[stkNum];

			// new top assigned
			this->top[stkNum] = i;

			// put e in arr[i]
			this->arr[i] = e;
		}

		// pop from given stack
		int pop(int stkNum){
			if(this->top[stkNum]==-1){
				cout<<"Stack Underflow"<<endl;
				return INT_MAX;
			}

			// find index of top of given stack
			int i = this->top[stkNum];

			// change top to the next of this top
			this->top[stkNum] = this->next[i];

			// make the next of current top as freeSlot
			this->next[i] = this->freeSlot;

			// make the index from which we delete as next
			// available free index
			this->freeSlot = i;

			// return the data of the deleted top
			return arr[i];
		}
};

int main(){
	// creating 3 stacks in array of size 10
	int k = 3, n = 10;
	kStacks kstks(n,k);

	// Let us put some items in stack number 2
	kstks.push(15,2);
	kstks.push(45, 2);

    // Let us put some items in stack number 1
    kstks.push(17, 1);
    kstks.push(49, 1);
    kstks.push(39, 1);

    // Let us put some items in stack number 0
    kstks.push(11, 0);
    kstks.push(9, 0);
    kstks.push(7, 0);

    cout << "Popped element from stack 2 is " << kstks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << kstks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << kstks.pop(0) << endl;

    return 0;
}
