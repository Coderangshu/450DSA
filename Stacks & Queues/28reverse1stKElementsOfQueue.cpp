        

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    // take first k elements into a stack
    // push all of stack into queue
    // for the q.size()-k elements pop from
    // queue and push to it again
    stack<int> stk;
    int kd = q.size()-k;
    while(q.size()>kd){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
    for(int i=0;i<kd;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}
