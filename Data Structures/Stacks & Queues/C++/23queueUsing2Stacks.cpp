// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}
// } Driver Code Ends


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    // Your Code
    // using pop costly because this gives time complexity
    // of O(n), as only once the elements are transferred
    // to the other stack, for push costly the elements have 
    // to be pushed into one and when required to pop all the
    // elements have to be transferred to other stack pop to
    // return the front of queue and then again transfer back
    // all elements to the first stack so that the new element
    // pushed will be the new top (i.e. the new front)
    
    // POP COSTLY
    // x always pushed to s1
    s1.push(x);
    
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code       
        
        // variable to store the value to be returned
        int item;
        
        // POP COSTLY
        // when s2 empty then bottom of s1 contains
        // front thus transfer all to s2 then top is
        // front, s1 still continues to take in new
        // elements and when required to get front we
        // return top of s2 until empty then again we
        // transfer all s1 to s2 to get the front
        // thus O(n) is the max time but average time
        // is O(1) many a times for popping the front
        
        // if both stacks empty means queue is empty
        if(s1.empty() and s2.empty()) return -1;
        
        // else
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            item = s2.top();
            s2.pop();
        }
        else{
            item = s2.top();
            s2.pop();
        }
        return item;
}

