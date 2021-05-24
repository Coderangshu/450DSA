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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(!head or !head->next) return head;
        Node *nextNode = divide(N-1,head->next);
        // If head is even or nextNode is odd,
        // nextNode data odd means that there
        // are no even numbers yet in the chain
        // with nextNode as its head.
        // Thus for both the cases the head gets
        // fixed at the beginning and remains as
        // the head of all the chain as of now.
        if(head->data%2==0 or nextNode->data%2!=0){
            head->next = nextNode;
            return head;
        }
        // When head odd and also nextNode is even
        // Here we go till the end of chain or 
        // until the even numbers end (whichever 
        // comes first), then we place the head
        // in between the last even number and 
        // rest of the chain (it may be null or 
        // may contain some odd numbers).
        else{
            Node *temp = nextNode;
            while(temp->next and temp->next->data%2==0){
                temp = temp->next;
            }
            Node *temp2 = temp->next;
            temp->next = head;
            head->next = temp2;
            return nextNode;
        }
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends
