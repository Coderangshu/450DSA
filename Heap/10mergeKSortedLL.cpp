// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

// compare function for calculating greater in queue
struct compare{
    bool operator()(struct Node *a, struct Node *b){
        return a->data>b->data;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    
    // Method II: Heap
    
    Node * mergeKLists(Node *arr[], int k)
    {
        // priority_queue 'pq' implemented as min heap
        // with the help of 'compare' function
        priority_queue<Node*,vector<Node*>,compare> pq;
        
        // push the head nodes of all the k lists in 'pq'
        for (int i = 0; i < k; i++)
            if (arr[i] != NULL)
                pq.push(arr[i]);
        
        // Handles the case when k = 0
        // or lists have no elements in them   
        if (pq.empty()) return NULL;
        
        // ansHead is created as a pointer to the first node
        // of the resultant link list
        struct Node *ansHead = new Node(-1);
        struct Node *tail = ansHead;
        
        while(!pq.empty()){
            
            // Get top heap(priority queue) as it contains the
            // smallest element of all k elements present inside
            // it
            Node *smallest = pq.top();
            pq.pop();
            
            // Adding smallest element retrived into answer link list
            if(ansHead->data==-1){
                ansHead = smallest;
                tail = smallest;
            }
            else{
                tail->next = smallest;
                tail = tail->next;
            }
            
            // Now we check if smallest's next isn't NULL we enter it
            // into the heap(priority queue)
            if(smallest->next!=NULL) pq.push(smallest->next);
        }
        return ansHead;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends
