// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

// Recursive
Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1==NULL or head2==NULL) return NULL;
    if(head1->data==head2->data){
        Node *nn = new Node(head1->data);
        nn->next = findIntersection(head1->next,head2->next);
        return nn;
    }
    if(head1->data<head2->data) return findIntersection(head1->next,head2);
    return findIntersection(head1,head2->next);
}

// Iterative
Node* findIntersection1(Node* head1, Node* head2)
{
    // Your Code Here
    Node *f=head1, *s=head2, *res=NULL, *prev;
    while(f!=NULL and s!=NULL){
        if(f->data==s->data){
            if(res==NULL){
                Node *nn = new Node(f->data);
                res = nn;
                prev = nn;
            }
            else{
                Node *nn = new Node(f->data);
                prev->next = nn;
                prev = nn;
            }
            f = f->next;
            s = s->next;
        }
        else{
            if(f->data<s->data) f = f->next;
            else s = s->next;
        }
    }
    return res;
}
