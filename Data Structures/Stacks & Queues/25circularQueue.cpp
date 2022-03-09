#include<bits/stdc++.h>
using namespace std;

class cQueue{
	private:
		int *queue, front, rear, size;
	public:
		// constructor
		cQueue(int s){
			this->size = s;
			this->queue = new int[s];
			this->front = -1;
			this->rear = -1;
		}

		void enqueue(int item){
			if((this->front==0 and this->rear==this->size-1)
					or (this->rear==this->front-1)){
				cout<<"Queue is full\n";
				return;
			}
			// if first element
			else if(this->front==-1){
				this->front = this->rear = 0;
				this->queue[front] = item;
			}
			// else when rear is last but front isn't first
			else if(this->rear==this->size-1 and this->front!=0){
				this->rear = 0;
				this->queue[this->rear] = item;
			}
			// else when front is 0 but rear isn't last
			else{
				this->rear++;
				this->queue[this->rear] = item;
			}
		}

		int dequeue(){
			if(this->front==-1){
				cout<<"Queue is empty\n";
				return INT_MAX;
			}
			int item = this->queue[this->front];
			// removing front from queue
			this->queue[this->front] = -1;
			// when front equals rear means this was
			// the last element of queue now queue is empty
			if(this->front==this->rear){
				this->front = -1;
				this->rear = -1;
			}
			// else if front is last of queue then next is 0
			else if(this->front==this->size-1) this->front = 0;
			else this->front++;

			return item;
		}

		void displayQueue(){
			if(this->front==-1){
				cout<<"Queue is empty\n";
				return;
			}
			cout<<"Elements in circular queue are: ";
			if(this->rear>=this->front){
				for(int i=this->front;i<=this->rear;i++)
					cout<<this->queue[i]<<" ";
			}
			else{
				for(int i=this->front;i<this->size;i++)
					cout<<this->queue[i]<<" ";
				for(int i=0;i<=this->rear;i++)
					cout<<this->queue[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	cQueue q(5);

	q.enqueue(14);
	q.enqueue(22);
	q.enqueue(13);
	q.enqueue(-6);

	q.displayQueue();

	cout<<"Deleted value: "<<q.dequeue()<<endl;
	cout<<"Deleted value: "<<q.dequeue()<<endl;

	q.displayQueue();

	q.enqueue(9);
	q.enqueue(20);
	q.enqueue(5);

	q.displayQueue();

	q.enqueue(20);

	cout<<"Deleted value: "<<q.dequeue()<<endl;
	cout<<"Deleted value: "<<q.dequeue()<<endl;

	q.displayQueue();

	cout<<"Deleted value: "<<q.dequeue()<<endl;

	q.displayQueue();

	cout<<"Deleted value: "<<q.dequeue()<<endl;

	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);

	q.displayQueue();

	q.enqueue(9);

	q.displayQueue();

	cout<<"Deleted value: "<<q.dequeue()<<endl;
	cout<<"Deleted value: "<<q.dequeue()<<endl;
	cout<<"Deleted value: "<<q.dequeue()<<endl;
	cout<<"Deleted value: "<<q.dequeue()<<endl;

	q.enqueue(10);
	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(13);
	q.enqueue(14);

	q.displayQueue();

	return 0;
}
