#include<bits/stdc++.h>
using namespace std;

class Queue{
	private:
		int maxSize,size = 0;
		int front = 0, rear = -1;
		int *queue;
	public:
		Queue(int s){
			this->maxSize = s;
			this->queue = new int[s];
		}

		void enqueue(int e){
			if(this->isFull()){
				cout<<"Queue is full."<<endl;
				return;
			}
			this->rear = (this->rear+1)%this->maxSize;
			this->queue[this->rear] = e;
			this->size++;
		}

		int dequeue(){
			if(this->isEmpty()){
				cout<<"Queue is empty."<<endl;
				return INT_MIN;
			}
			int e = this->queue[this->front];
			this->front = (this->front+1)%this->maxSize;
			this->size--;
			return e;
		}

		bool isFull(){
			return (this->size==this->maxSize);
		}

		bool isEmpty(){
			return (this->size==0);
		}

		int Front(){
			return this->queue[this->front];
		}

		int Back(){
			return this->queue[this->rear];
		}

		int Size(){
			return this->size;
		}
};

int main(){
	Queue q(3);
	cout<<"Size: "<<q.Size()<<endl;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	cout<<"Front: "<<q.Front()<<" Back: "<<q.Back()<<" Size: "<<q.Size()<<endl;
	cout<<"Dequeued: "<<q.dequeue()<<endl;;
	q.enqueue(4);
	cout<<"Front: "<<q.Front()<<" Back: "<<q.Back()<<" Size: "<<q.Size()<<endl;
	cout<<"Dequeued: "<<q.dequeue()<<endl;;
	cout<<"Dequeued: "<<q.dequeue()<<endl;;
	cout<<"Dequeued: "<<q.dequeue()<<endl;;
	cout<<"Dequeued: "<<q.dequeue()<<endl;;
	q.enqueue(5);
	q.enqueue(6);
	cout<<"Dequeued: "<<q.dequeue()<<endl;;
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	cout<<"Front: "<<q.Front()<<" Back: "<<q.Back()<<" Size: "<<q.Size()<<endl;

	return 0;
}
