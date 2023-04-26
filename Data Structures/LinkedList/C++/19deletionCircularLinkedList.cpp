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
    do{
        cout<<cur->data<<" ";
        cur = cur->next;
    }while(cur!=head);
    cout<<endl;
}

Node* deleteNode(Node *head, int delKey){
	if(!head) return head;
	auto cur = head;
	Node *prev = head->next;
	while(prev->next!=head) prev = prev->next;
	do{
		if(cur->data==delKey){
			prev->next = cur->next;
			if(cur==head) head = cur->next;
			free(cur);
			break;
		}
		prev = cur;
		cur = cur->next;
	}while(cur!=head);
	return head;
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
	cur->next = head;
	int delKey;
	cin>>delKey;
    printLL(head);
    auto newHead = deleteNode(head, delKey);
    printLL(newHead);
    return 0;
}