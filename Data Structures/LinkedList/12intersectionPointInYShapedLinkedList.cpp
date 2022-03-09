// { Driver Code Starts
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.

// Modified Floyd Cycle Detection
// Algorithm:
// Using Two pointers :
//     Initialize two pointers ptr1 and ptr2  at the head1 and  head2.
//     Traverse through the lists,one node at a time.
//     When ptr1 reaches the end of a list, then redirect it to the head2.
//     similarly when ptr2 reaches the end of a list, redirect it the head1.
//     Once both of them go through reassigning, they will be equidistant from
//     the collision point
//     If at any node ptr1 meets ptr2, then it is the intersection node.
//     After second iteration if there is no intersection node it returns NULL.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *f=head1, *s=head2;
    while(f!=s){
        if(f==NULL) f = head2;
        if(s==NULL) s = head1;
        f = f->next;
        s = s->next;
    }
    // There will be two cases when the while loop breaks,
    // either if an intersection is present or if there is
    // no intersection thus both pointer reach NULL and become
    // equal. So if any of the pointer is NULL means no intersection.
    if(f) return f->data;
    else  return 0;
}


