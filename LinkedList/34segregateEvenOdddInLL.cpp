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
private:
    // TC : O(n^2), SC : O(n) (recursive stack)
    Node * recursion(Node *head){
        if(!head or !head->next) return head;
        Node *nextNode = recursion(head->next);
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

    // recursive function to return {head,last even node node}
    // TC : O(n), SC : O(n) (recursive stack)
    pair<Node*,Node*> recursion1(Node *head){
        if(!head->next) return (head->data%2==0)?make_pair(head,head):make_pair(head,nullptr);
        auto p = recursion1(head->next);
        auto nextNode = p.first, lastEvenNode = p.second;
        if(head->data%2!=0 and nextNode->data%2==0){
            auto tempNext = lastEvenNode->next;
            lastEvenNode->next = head;
            head->next = tempNext;
            return {nextNode,lastEvenNode};
        }
        else{
            head->next = nextNode;
            if(head->data%2==0 and nextNode->data%2!=0) return {head,head};
            else return {head,lastEvenNode};
        }
    }

    // iterative approach = seperating even and odd nodes into 2 lists
    // then adding them back together
    // TC : O(n), SC : O(1)
    Node *iterative(Node *head){
        if(!head or !head->next) return head;
        Node *evenHead = nullptr, *evenTail = nullptr, *oddHead = nullptr, *oddTail = nullptr;
        while(head){
            if(head->data%2==0){
                if(!evenHead) evenHead = head;
                else evenTail->next = head;
                evenTail = head;
            }
            else{
                if(!oddHead) oddHead = head;
                else oddTail->next = head;
                oddTail = head;
            }
            head = head->next;
        }
        if(evenTail) evenTail->next = oddHead;
        else evenHead = oddHead;
        if(oddTail) oddTail->next = nullptr;
        return evenHead;
    }

public:
    Node* divide(int N, Node *head){
        // code here
        // return recursion(head);
        // return recursion1(head).first;
        return iterative(head);
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
