#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *prev, *next;
	Node(int i){
		this->data = i;
		this->prev = NULL;
		this->next = NULL;
	}
}node;

class Stack{
	private:
		node *head;
		node *mid;
		int Size;
	public:
		Stack(){
			this->head = NULL;
			this->mid = NULL;
			this->Size = 0;
		}

		void push(int e){
			node *nn = new node(e);
			this->Size++;
			
			// connecting nn to stack
			if(this->Size!=1){
				this->head->prev = nn;
				nn->next = this->head;
			}
			
			// mid changes only when size is even
			// handling the initial condition
			// seperately
			if(this->Size==1) this->mid = nn;
			else if(this->Size%2!=1) this->mid = this->mid->prev;
			
			// shifting head to current node
			this->head = nn;
		}

		int pop(){
			node *toBeDeleted = this->head;
			int delNum = toBeDeleted->data;
			this->Size--;

			// mid changes only when size becomes odd
			if(this->Size%2==1) this->mid = this->mid->next;

			// disconnecting node
			this->head = this->head->next;

			free(toBeDeleted);
			return delNum;
		}

		int size(){return this->Size;}

		node* findMid(){return this->mid;}

		node* top(){return this->head;}

		int delMid(){
			this->Size--;
			node *toBeDeleted = this->mid;
			int delNum = toBeDeleted->data;

			// relocating the mid pointer to new mid

			// when after deletion size becomes even
			if(this->Size%2!=1) this->mid = this->mid->prev;
			// when after deletion size becomes odd
            else this->mid = this->mid->next;

			// disconnecting the node
            // when there are more than 2 nodes
            if(this->Size>2){
                node *nxt = toBeDeleted->next;
                node *prv = toBeDeleted->prev;
                nxt->prev = prv;
                prv->next = nxt;
            }

            // when there are 2 nodes only
            else if(this->Size==2){
                node *nxt = toBeDeleted->next;
                this->head->next = nxt;
            }
            // when only 1 node
            else this->head = this->mid;

			free(toBeDeleted);
			return delNum;
		}
};

int main(){
	Stack stk;
	
	// Pushing data into stack
	cout<<"Pushing data into stack"<<endl;
    for(int i=1;i<=10;i++){
        stk.push(i);
        cout<<"Top: "<<stk.top()->data<<" Size: "<<stk.size()<<" Mid: "<<stk.findMid()->data<<endl;
    }

	// Popping data from stack
	cout<<"Popping data from stack"<<endl;
    for(int i=0;i<10;i++)
        cout<<"Popped data: "<<stk.pop()<<" Size: "<<stk.size()<<" Mid: "<<stk.findMid()->data<<endl;

	// Pushing data into stack again
	cout<<"Pushing data into stack"<<endl;
    for(int i=1;i<=10;i++){
        stk.push(i);
        cout<<"Top: "<<stk.top()->data<<" Size: "<<stk.size()<<" Mid: "<<stk.findMid()->data<<endl;
    }

    // Deleting middle node
    for(int i=0;i<5;i++)
        cout<<"Mid del: "<<stk.delMid()<<" Size: "<<stk.size()<<" Mid: "<<stk.findMid()->data<<endl;

    // Pushing data into stack again
	cout<<"Pushing data into stack"<<endl;
    for(int i=1;i<=5;i++){
        stk.push(i);
        cout<<"Top: "<<stk.top()->data<<" Size: "<<stk.size()<<" Mid: "<<stk.findMid()->data<<endl;
    }

	return 0;
}
