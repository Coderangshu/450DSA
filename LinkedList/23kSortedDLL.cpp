#include<bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};


// function to sort a k sorted doubly linked list
// using insertion sorting algorithm
// Time complexity: O(n*k)
// Space complexity: O(1)
struct Node* sortAKSortedDLL(struct Node* head, int k)
{
	if(head == NULL || head->next == NULL)
		return head;

	// perform on all the nodes in list
	for(Node *i = head->next; i != NULL; i = i->next) {
		Node *j = i;
		// There will be atmost k swaps for each element in the list
		// since each node is k steps away from its correct position
		while(j->prev != NULL && j->data < j->prev->data) {
			// swap j and j.prev node
			Node* pprev = j->prev->prev;
			Node* prev = j->prev;
			Node *next = j->next;
			j->prev->next = next;
			j->prev->prev = j;
			j->prev = pprev;
			j->next = prev;
			if(pprev != NULL) pprev->next = j;
			if(next != NULL) next->prev = prev;
		}
		// if j is now the new head
        // then reset head
		if(j->prev == NULL) head = j;
	}
	return head;
}

Node *ksort(Node *head, int k){
    Node *cur = head;
    if(!cur->next) return nullptr;
    cur = cur->next;
    Node *i, *j;
    while(cur){
        i = cur->prev;
        j = cur;
        int counter = k;
        while(i and i->data>j->data and counter){
            swap(i->data, j->data);
            i = i->prev;
            j = j->prev;
            counter--;
        }
        cur = cur->next;
    }
}

// 'compare' function used to build up the
// priority queue
struct compare {
    bool operator()(struct Node* p1, struct Node* p2)
    {
        return p1->data > p2->data;
    }
};

// function to sort a k sorted doubly linked list
struct Node* sortAKSortedDLL1(struct Node* head, int k)
{
    // if list is empty
    if (head == NULL) return head;
 
    // priority_queue 'pq' implemented as min heap with the
    // help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;
 
    struct Node* newHead = NULL, *last;
 
    // Create a Min Heap of first (k+1) elements from
    // input doubly linked list
    for (int i = 0; head != NULL && i <= k; i++) {
        // push the node on to 'pq'
        pq.push(head);
 
        // move to the next node
        head = head->next;
    }
 
    // loop till there are elements in 'pq'
    while (!pq.empty()) {
 
        // place root or top of 'pq' at the end of the
        // result sorted list so far having the first node
        // pointed to by 'newHead'
        // and adjust the required links
        if (newHead == NULL) {
            newHead = pq.top();
            newHead->prev = NULL;
 
            // 'last' points to the last node
            // of the result sorted list so far
            last = newHead;
        }
 
        else {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
 
        // remove element from 'pq'
        pq.pop();
 
        // if there are more nodes left in the input list
        if (head != NULL) {
            // push the node on to 'pq'
            pq.push(head);
 
            // move to the next node
            head = head->next;
        }
    }
 
    // making 'next' of last node point to NULL
    last->next = NULL;
 
    // new head of the required sorted DLL
    return newHead;
}


// Function to insert a node at the beginning
// of the Doubly Linked List
void push(struct Node** head_ref, int new_data)
{
	// allocate node
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	// put in the data
	new_node->data = new_data;

	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list off the new node
	new_node->next = (*head_ref);

	// change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(struct Node* head)
{
	// if list is empty
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	struct Node* head = NULL;

	// Create the doubly linked list:
	// 3<->6<->2<->12<->56<->8
	push(&head, 8);
	push(&head, 56);
	push(&head, 12);
	push(&head, 2);
	push(&head, 6);
	push(&head, 3);

	int k = 2;

	cout << "Original Doubly linked list:\n";
	printList(head);

	// sort the biotonic DLL
	head = sortAKSortedDLL(head, k);

	cout << "\nDoubly linked list after sorting:\n";
	printList(head);

	return 0;
}
