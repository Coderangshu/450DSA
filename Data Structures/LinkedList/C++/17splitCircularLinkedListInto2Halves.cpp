// { Driver Code Starts
/* Program to split a circular linked list into two halves */
#include<stdio.h> 
#include<stdlib.h> 
 
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
}; 

void splitList(struct Node *head, struct Node **head1_ref,   struct Node **head2_ref);
 struct Node* newNode(int key)
{
    struct Node *temp = new Node(key);
    
    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
  struct Node *temp = head; 
  if(head != NULL)
  {
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
    printf("\n");
  }
}

 
/* Driver program to test above functions */
int main()
{
  
   int t,n,i,x;
    scanf("%d",&t);
   while(t--)
   {
	   struct Node *temp,*head = NULL;
       struct Node *head1 = NULL;
       struct Node *head2 = NULL;
	   scanf("%d",&n);
	   scanf("%d",&x);
	   head=new Node(x);
	   temp=head;
	   for(i=0;i<n-1;i++){
	   scanf("%d",&x);
	   
	   temp->next=new Node(x);
	   
	   temp=temp->next;
	       
	   }
       
       temp->next=head;
  
       splitList(head, &head1, &head2);
  
     // printf("\nFirst Circular Linked List");
      printList(head1);  
 
     // printf("\nSecond Circular Linked List");
      printList(head2);  
   
   }
  return 0;
}
// } Driver Code Ends


/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

// QUESTION
// Given a Cirular Linked List of size N, split it into two halves circular lists.
// If there are odd number of nodes in the given circular linked list then out of
// the resulting two halved lists, first list should have one node more than the
// second list. The resultant lists should also be circular lists and not linear lists.

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    *head1_ref = head;
    auto cur = head, slow = head, fast = head;
    while(fast->next!=head and fast->next->next!=head){
        slow = slow->next;
        fast = fast->next->next;
    }
    // The above while loop will terminate either at 
    // the last node before head (when odd number of nodes are present),
    // or second last node before head (when even number of nodes are present).

    *head2_ref = slow->next;
    slow->next = head;

    // When odd number of nodes
    if(fast->next==head) fast->next = *head2_ref;
    // else when even number of nodes
    else fast->next->next = *head2_ref;
}
