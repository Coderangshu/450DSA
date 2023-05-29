// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node *listSplitter(Node *head){
        Node *tortoise = head, *rabbit = head, *prev = nullptr;
        while(!rabbit->next->next and !rabbit->next){
            prev = tortoise;
            rabbit = rabbit->next->next;
            tortoise = tortoise->next;
        }
        prev->next = nullptr;
        // If doubly linked list then uncomment below line rest all functions same
        // tortoise->prev = nullptr;
        return tortoise;
    }
    
    
    // This is the sorter and the merger recursion function
    Node *merge(Node *first, Node *second){
        if(!first) return second;
        else if(!second) return first;
        if(first->data<=second->data){
            first->next = merge(first->next,second);
            // If doubly linked list then uncomment below line rest all functions same
            // if(first->next) first->next->prev = first;
            return first;
        }
        else{
            second->next = merge(first,second->next);
            // If doubly linked list then uncomment below line rest all functions same
            // if(second->next) second->next->prev = second;
            return second;
        }
    }

    
    // This is the divider recursion function
    Node* mergeSort(Node* head) {
        // your code here
        if(!head or !head->next) return head;
        Node *second = listSplitter(head);
        head = mergeSort(head);
        second = mergeSort(second);
        return merge(head,second);
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
