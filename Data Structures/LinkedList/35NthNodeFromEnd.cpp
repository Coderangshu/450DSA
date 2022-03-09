// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.

void recursion(Node *head, int n, int *addr){
    static int i = 0;
    if(!head) return;
    recursion(head->next,n,addr);
    i++;
    if(i==n) *addr = (head->data);
    
}

int getNthFromLast(Node *head, int n)
{
       // Your code here
      int a = -1;
       recursion(head,n,&a);
    //   cout<<a<<endl;
       return a;
}


// Iterative
int getNthFromLastI(Node *head, int n)
{
       // Your code here
       int len = 0;
       auto cur = head;
       while(cur) len++, cur = cur->next;
       int reqN = len-n;
       if(reqN<0) return -1;
       cur = head;
       while(reqN--) cur = cur->next;
       return cur->data;
}