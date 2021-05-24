// { Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        // Initialize count of '0', '1' and '2' as 0
        int count[3] = {0, 0, 0};
        Node *ptr = head;
 
        /* count total number of '0', '1' and '2'
        * count[0] will store total number of '0's
        * count[1] will store total number of '1's
        * count[2] will store total number of '2's */
        while (ptr != NULL)
        {
            count[ptr->data] += 1;
            ptr = ptr->next;
        }
     
        int i = 0;
        ptr = head;
     
        /* Let say count[0] = n1, count[1] = n2 and count[2] = n3
        * now start traversing list from head node,
        * 1) fill the list with 0, till n1 > 0
        * 2) fill the list with 1, till n2 > 0
        * 3) fill the list with 2, till n3 > 0 */
        while (ptr != NULL)
        {
            if (count[i] == 0)
                i++;
            else
            {
                ptr->data = i;
                count[i]--;
                ptr = ptr->next;
            }
        }
        return head;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends
