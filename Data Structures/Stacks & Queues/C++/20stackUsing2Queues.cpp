// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */



// Two ways : make push operation costly or pop operation costly

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        
        // to handle whether use push or pop costly
        // 1 means push costly 0 means pop costly
        // change the handler in pop funtion also
        // accordingly
        int handler = 0;
        
        if(handler){
            // PUSH COSTLY
            // new element enqueued to q2, then dequeue
            // q1 and enqueue all into q2, then swap
            // names, this way new element is always enqueued
            // into q2 and top remains in q2.front()
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            // swapping names
            queue<int> temp = q1;
            q1 = q2;
            q2 = temp;
        }else{
            // POP COSTLY
            // new element always pushed to q2, this way
            // top remains in q2.back() always
            q2.push(x);
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code       
        
        int handler = 0;
        
        if(handler){
            // PUSH COSTLY
            // always pop from q1 as q1 keeps the top
            // in front always
            if(q1.empty()) return -1;
            int item = q1.front();
            q1.pop();
            return item;
        }else{
            // POP COSTLY
            // dequeue q2 until only one left in it(top)
            // enqueue all in q1, swap names
            if(q2.empty()) return -1;
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int item = q2.front();
            q2.pop();
            // swapping names
            queue<int> temp = q1;
            q1 = q2;
            q2 = temp;
            return item;
        }
}
