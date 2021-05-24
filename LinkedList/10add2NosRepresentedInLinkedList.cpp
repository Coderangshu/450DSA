// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    int linkedListLen(struct Node*head){
        int count = 0;
        Node *c = head;
        while(c!=NULL){
            count++;
            c = c->next;
        }
        return count;
    }
    
    int addCarryToExtraLength(Node *head, int carry){
        if(head->next==NULL){
            int a = head->data+carry;
            head->data = a%10;
            return a/10;
        }
        int a = addCarryToExtraLength(head->next,carry);
        int aa = head->data+a;
        head->data = aa%10;
        return aa/10;        
    }
    
    int addSameSizeLists(struct Node* first, struct Node* second, struct Node* res){
        if(first->next==NULL){
            int ans = first->data+second->data;
            // cout<<first->data<<" "<<second->data<<endl;
            res->data = ans%10;
            return ans/10;
        }
        Node *nr = new Node(0);
        int carry = addSameSizeLists(first->next,second->next,nr);
        int ans = first->data+second->data+carry;
        res->data = ans%10;
        res->next = nr;
        return ans/10;
    }
    
    struct Node* addListsUtil(struct Node* first, struct Node* second, struct Node* res){
        int len1 = linkedListLen(first);
        int len2 = linkedListLen(second);
        if(len1==len2){
            int carry = addSameSizeLists(first,second,res);
            if(carry!=0){
                Node *nn = new Node(carry);
                nn->next = res;
                return nn;
            }
            return res;
        }
        else if(len1>len2){
            int diff = len1-len2;
            Node *ff = first, *prev;
            while(diff>0){
                prev = ff;
                ff = ff->next;
                diff--;
            }
            int carry = addSameSizeLists(ff,second,res);
            prev->next = NULL;
            carry = addCarryToExtraLength(first,carry);
            prev->next = res;
            if(carry!=0){
                Node *nn = new Node(carry);
                nn->next = first;
                return nn;
            }
            return first;
        }
        else if(len1<len2){
            int diff = len2-len1;
            Node *fs = second, *prev;
            while(diff>0){
                prev = fs;
                fs = fs->next;
                diff--;
            }
            int carry = addSameSizeLists(first,fs,res);
            prev->next = NULL;
            carry = addCarryToExtraLength(second,carry);
            prev->next = res;
            if(carry!=0){
                Node *nn = new Node(carry);
                nn->next = second;
                return nn;
            }
            return second;
        }
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *res = new Node(0);
        Node *ans = addListsUtil(first,second,res);
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
