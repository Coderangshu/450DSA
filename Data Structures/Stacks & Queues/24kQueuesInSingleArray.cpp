#include<bits/stdc++.h>
using namespace std;

class kQueues{
	private:
		// pointer to array to store the elements of all k arrays
		// and front and rear
		int *arr, *front, *rear;

		// pointer to next array whose ith index stores next empty
		// space when arr[i] is empty and when arr[i] is filled
		// then next[i] stores the index where the next element
		// of that queue is stored
		int *next;

		// n is size of array and k is number of queues
		int n, k;

		// to store the next free index in arr
		int next_free;

	public:
		// constructor
		kQueues(int k, int n){
			this->k = k;
			this->n = n;
			this->arr = new int[n];
			this->front = new int[k];
			this->rear = new int[k];
			this->next = new int[n];
			this->next_free = 0;

			// filling front and rear for all k queues
			// as -1 as all are empty now
			for(int i=0;i<k;i++){
				front[i] = -1;
				rear[i] = -1;
			}

			// filling all next with the next empty node
			for(int i=0;i<n-1;i++) next[i] = i+1;
			// the last of next has no next empty thus storing -1
			next[n-1] = -1;
		}

		void enqueue(int item, int qNum){
			if(this->isFull(qNum)){
				cout<<"Queue is full\n";
				return;
			}
			int i = this->next_free;
			// updating the next_free
			this->next_free = next[i];

			if(this->front[qNum]==-1) this->front[qNum] = i;
			else this->next[this->rear[qNum]] = i;

			// update rear
			this->rear[qNum] = i;

			// put item in arr
			this->arr[i] = item;
		}

		int dequeue(int qNum){
			if(isEmpty(qNum)){
				cout<<"Queue is empty\n";
				return INT_MAX;
			}
			// get index of front of qNum queue
			int i = this->front[qNum];

			// make the next of current front as the new front
			this->front[qNum] = this->next[i];

			// now as arr[i] is empty the task of next[i] is to
			// point to the next empty space again, thus assigning
			// the next empty space of i in next[i]
			this->next[i] = this->next_free;

			// the new next_free becomes the i as it is empty
			this->next_free = i;

			// return the dequeued element
			return arr[i];
		}

		bool isEmpty(int qNum){return (this->front[qNum]==-1);}

		bool isFull(int qNum){return (this->next_free==-1);}
};

int main(){
	// Let us create 3 queue in an array of size 10
    int k = 3, n = 10;
    kQueues ks(k, n);

    // Let us put some items in queue number 2
    // Let us put some items in queue number 1
    // Let us put some items in queue number 0
	
    ks.enqueue(15, 2);
    ks.enqueue(17, 1);
    ks.enqueue(45, 2);
    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(39, 1);
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    ks.enqueue(7, 0);
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

    return 0;
}
