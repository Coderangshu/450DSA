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
	if(!head or !head->next) return head;
	// perform on all the nodes beginning from the 2nd
	for(Node *cur = head->next; cur != nullptr;) {
		Node *curNext = cur->next;
        int counter = k;
		// There will be atmost k swaps for each element in the list
		// since each node is k steps away from its correct position
		while(counter-- and cur->prev and cur->data < cur->prev->data) {
            // store previous to prev, prev and next of cur
			Node *pprev = cur->prev->prev, *prev = cur->prev, *next = cur->next;
			// swap prev and cur node
            cur->next = prev;
            prev->prev = cur;
            // connect the 2 swapped nodes back to the linked list
            cur->prev = pprev;
            prev->next = next;
			if(pprev) pprev->next = cur;
			if(next) next->prev = prev;
		}
		// if j is now the new head
        // then reset head
		if(!cur->prev) head = cur;
        cur = curNext;
	}
	return head;
}

// Same as above using while loop instead of for loop
Node *ksort(Node *head, int k){
    if(!head or !head->next) return head;
    Node *cur = head;
    if(!cur->next) return cur;
    cur = cur->next;
    while(cur){
        Node *curNext = cur->next;
        int counter = k;
        while(counter-- and cur->prev and cur->data < cur->prev->data){
            Node *pprev = cur->prev->prev, *prev = cur->prev, *next = cur->next;
            cur->next = prev;
            prev->prev = cur;
            cur->prev = pprev;
            prev->next = next;
			if(pprev) pprev->next = cur;
			if(next) next->prev = prev;
        }
        if(!cur->prev) head = cur;
        cur = curNext;
    }
    return head;
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
    if (head == nullptr) return head;
 
    // priority_queue 'pq' implemented as min heap with the
    // help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;
 
    struct Node* newHead = nullptr, *last;
 
    // Create a Min Heap of first (k+1) elements from
    // input doubly linked list
    for (int i = 0; head != nullptr && i <= k; i++) {
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
        if (newHead == nullptr) {
            newHead = pq.top();
            newHead->prev = nullptr;
 
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
        if (head != nullptr) {
            // push the node on to 'pq'
            pq.push(head);
 
            // move to the next node
            head = head->next;
        }
    }
 
    // making 'next' of last node point to nullptr
    last->next = nullptr;
 
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
	// prev is always nullptr
	new_node->prev = nullptr;

	// link the old list off the new node
	new_node->next = (*head_ref);

	// change prev of head node to new node
	if ((*head_ref) != nullptr)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(struct Node* head)
{
	// if list is empty
	if (head == nullptr)
		cout << "Doubly Linked list empty";

	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	struct Node* head = nullptr;

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
