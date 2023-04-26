// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
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

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    
    // Hashmap approach
    bool detectLoop(Node* head){
        unordered_set<Node*> s;
        while(head!=NULL){
            if(s.find(head)!=s.end()) return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
    
    // Floyd cycle detection algorithm(fastest)
    bool detectLoop1(Node* head)
    {
        // your code here
        Node *tortoise = head, *hare = head;
        // Here the loop continues until any of  
        // the tortoise or hare reaches NULL,
        //hare->next is also checked to prevent
        // the hare->next->next from going out
        // of index.
        // When hare and tortoise matches this means
        // that there is a loop in the list.
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                return true;
            }
        }
        return false;
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
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}
  // } Driver Code Ends
