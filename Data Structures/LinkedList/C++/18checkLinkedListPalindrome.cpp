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
        if(!head->next) return head;
        Node *rest = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        // Getting mid element in tortoise
        // And also determining whether length
        // is odd or even with help of rabbit.
        if(!head->next) return true;
        auto slow = head, fast = head;
        Node *prev = nullptr;
        while(fast->next and fast->next->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        Node *head2 = slow->next;
        
        // when there's fast->next means linked list is of even length
        // break the linked list after slow
        if(fast->next) slow->next = nullptr;

        // when fast->next is null means liked list is of odd length
        // break after prev and free the slow
        else{
            prev->next = nullptr;
            free(slow);
        }

        // reverse the second linked list
        head2 = reverse(head2);
        // traverse both linked list if non matching data found
        // return false if both linked list traversed completely
        // return true
        while(head and head2){
            if(head->data!=head2->data) return false;
            head = head->next;
            head2 = head2->next;
        }
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
