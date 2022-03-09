#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

void printLL(Node *head){
    auto cur = head;
    while(cur){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

Node* changeHead(Node *head){
    if(!head) return nullptr;
    Node *cur = head, *prev;
    while(cur->next){
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;
    cur->next = head;
    return cur;
}

int main(){
    int n;
    cin>>n;
    Node *head, *cur;
    int e;
    cin>>e;
    head = new Node(e);
    cur = head;
    for(int i=1;i<n;i++){
        cin>>e;
        cur->next = new Node(e);
        cur = cur->next;
    }
    printLL(head);
    auto changedHead = changeHead(head);
    printLL(changedHead);
    return 0;
}
