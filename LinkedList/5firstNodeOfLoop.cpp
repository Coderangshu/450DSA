// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    Node* firstNode(Node* head)
    {
        // code here
        Node *tortoise = head, *hare = head;
        bool present=false;
            while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                present = true;
                break;
            }
        }
        if(present){
            tortoise = head;
            while(tortoise!=hare){
                tortoise = tortoise->next;
                hare = hare->next;
            }
            return tortoise;
        }
        else return nullptr;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        auto firstNode = ob.firstNode(head);
        
        cout<<"First Node of the loop is: ";
        cout<<firstNode->data<<endl;
    }
	return 0;
}
  // } Driver Code End
