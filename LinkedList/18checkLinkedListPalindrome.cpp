// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node *reverse(Node *head){
        // cout<<head->data<<endl;
        if(head->next==NULL) return head;
        Node *rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        // Getting mid element in tortoise
        // And also determining whether length
        // is odd or even with help of rabbit.
        if(head->next==NULL) return true;
        Node *tortoise = head, *rabbit = head, *prev;
        while(1!=0){
            if(rabbit->next==nullptr) break;
            if(rabbit->next->next==nullptr) break;
            rabbit = rabbit->next->next;
            prev = tortoise;
            tortoise = tortoise->next;
            if(rabbit->next==nullptr) break;
            if(rabbit->next->next==nullptr)break;
        }
        
        // If linked list length is odd we remove
        // the middle element of the linked list
        if(rabbit->next==NULL){
            prev->next = tortoise->next;
            free(tortoise);
        }
        // If length is even then just assigning tortoise
        // to prev to keep a similarity of terminology in
        // future.
        else prev = tortoise;
        
        // We divide the linked list at the midpoint
        // as now the length is even thus we get two
        // equal length linked list.
        // We reverse the second linked list and then
        // join it with the first linked list
        Node *sh = prev->next;
        prev->next = NULL;
        prev->next = reverse(sh);
        
        // Now we compare each element in each half
        // if any of them not equal thus the list is
        // not palindromic
        Node *apparent_head2 = prev->next;
        Node *current = head;
        while(current!=prev->next){
            if(current->data!=apparent_head2->data) return false;
            current = current->next;
            apparent_head2 = apparent_head2->next;
        };
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
