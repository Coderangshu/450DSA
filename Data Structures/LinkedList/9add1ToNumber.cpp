// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    int recursionHelper(Node *head){
        if(head->next==NULL){
            int a = head->data+1;
            head->data = a%10;
            return a/10;
        }
        int a = recursion(head->next);
        int aa = head->data+a;
        head->data = aa%10;
        return aa/10;        
    }
    // Recursive approach
    Node* recursion(Node *head){
        int a = recursionHelper(head);
        if(a!=0){
            Node * nn = new Node(a);
            nn->next = head;
            head = nn;
        }
        return head;
    }
    // Iterative(stack) approach
    Node* iterative(Node *head) 
    {
        stack<Node*> stk;
        auto cur = head;
        while(cur){
            stk.push(cur);
            cur = cur->next;
        }
        int carry = 0;
        stk.top()->data += 1;
        carry = stk.top()->data/10;
        stk.top()->data %= 10;
        stk.pop();
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            top->data += carry;
            carry = top->data/10;
            top->data %= 10;
        }
        if(carry){
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        // Uncomment either of the below

        //return recursion(head);
        return iterative(head);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
