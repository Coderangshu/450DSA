// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    // Iterative approach using stack to reverse each group
    struct node *reverse1 (struct node *head, int k)
    { 
        // Complete this method
        node * current = head;
        node * prev = NULL;
        int count=0;
        stack<node *> stk;
        while(current!=NULL){
            count = 0;
            while(count<k and current!=NULL){
                stk.push(current);
                current = current->next;
                count++;
            }
            while(!stk.empty()){
                if(prev==NULL){
                    prev = stk.top();
                    head = prev;
                    stk.pop();
                }
                else{
                    prev->next = stk.top();
                    prev = prev->next;
                    stk.pop();
                }
            }
        }
        prev->next = NULL;
        return head;
    }
    
    // Rrecursive approach using pointer reversal for each group
    struct node *reverse (struct node *head, int k){
        node * current = head;
        node * prev = NULL;
        node * next = current->next;
        int count = 0;
        while(current!=NULL and count<k){
            // save current's next in next
            next = current->next;
            // put current's prev in its next
            current->next = prev;
            // Reversing of current's pointer done
            // now new prev is the current
            prev = current;
            // and the new current is the next
            current = next;
            count++;
        }
        // base condition
        if(next!=NULL) head->next = reverse(current,k);
        
        return prev;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends
