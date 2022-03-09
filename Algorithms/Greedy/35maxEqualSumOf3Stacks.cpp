#include<bits/stdc++.h>
#define int long long int
using namespace std;

struct structure{
    int* sum;
    vector<int> stack;
    int top;
    structure(int* s, vector<int> v, int t){
        sum = s;
        stack = v;
        top = t;
    }
};

struct compare{
    bool operator()(structure* s1, structure* s2){
        return *s1->sum<*s2->sum; 
    }
};

void solve(){
    vector<int> stack1 = { 3, 2, 1, 1, 1 };
    vector<int> stack2 = { 4, 3, 2 };
    vector<int> stack3 = { 1, 1, 4, 1 };

    int sum1 = accumulate(stack1.begin(),stack1.end(),0);
    int sum2 = accumulate(stack2.begin(),stack2.end(),0);
    int sum3 = accumulate(stack3.begin(),stack3.end(),0);

    // we take the stack with the max sum and remove top and push
    // into heap, then take the max sum and do the same
    // repeat until all 3 sums are equal

    // max heap containing (pointer to sum,stack,top's index)
    priority_queue<structure*,vector<structure*>,compare> maxHeap;
    structure* s = new structure(&sum1,stack1,0);
    maxHeap.push(s);
    s = new structure(&sum2,stack2,0);
    maxHeap.push(s);
    s = new structure(&sum3,stack3,0);
    maxHeap.push(s);

    while(sum1!=sum2 or sum2!=sum3 or sum3!=sum1){
        
        structure* ms = maxHeap.top();
        maxHeap.pop();
        *ms->sum -= ms->stack[ms->top];
        ms->top++;
        maxHeap.push(ms);
    }
    cout<<*maxHeap.top()->sum<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}