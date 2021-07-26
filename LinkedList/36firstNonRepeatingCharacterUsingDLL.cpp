// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    
	    struct node {
            char a;
            struct node *next, *prev;
        };
	
	    void appendNode(struct node** head_ref,struct node** tail_ref, char x){
            struct node* temp = new node;
            temp->a = x;
            temp->prev = temp->next = NULL;
          
            if (*head_ref == NULL) {
                *head_ref = *tail_ref = temp;
                return;
            }
            (*tail_ref)->next = temp;
            temp->prev = *tail_ref;
            *tail_ref = temp;
        }
	    
	    void removeNode(struct node** head_ref,struct node** tail_ref, struct node* temp){
            if (*head_ref == NULL)
                return;
          
            if (*head_ref == temp)
                *head_ref = (*head_ref)->next;
            if (*tail_ref == temp)
                *tail_ref = (*tail_ref)->prev;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
          
            delete (temp);
        }
	    

	    // The method used is we maintain 2 arrays inDLL and repeated
	    // both are of length 26(i.e. number of engilish alphabets)
	    // inDLL holds the address of the DLL node in which that index
	    // character is stored, and in repeated the index stores if
	    // a char has been repeated or not.
	    // A char is said to be repeated when obtained twice or more

	    // when repeated is false and inDLL of a char is NULL we know
	    // that this is the 1st time of a char, thus insert a DLL node
	    // of it in the DLL and put the address of the node in the inDLL
	    // when came across the char the 2nd time mark repeated as true,
	    // remove the node from DLL and make inDLL of that char as NULL.

	    // Now, at the end of an iteration we append to the answer the
	    // DLL's head's char as the head of the DLL will always be the
	    // 1st non repeating char upto that point, and if head is NULL
	    // then we no there's no repeating char thus append a '#'.


		string FirstNonRepeating(string A){
		    // Code here
		    struct node* inDLL[26] = {NULL};
  
            // repeated[x] is true if x is repeated two or more
            // times. If x is not seen so far or x is seen only
            // once. then repeated[x] is false
            bool repeated[26] = {false};
          
            // Initialize the above two arrays
            string ans = "";
            struct node *head = NULL, *tail = NULL;
          
            for (int i = 0; i<A.length(); i++) {
                char x = A[i];
          
                // We process this character only if it has not
                // occurred or occurred only once. repeated[x] is
                // true if x is repeated twice or more.s
                if (!repeated[x-'a']) {
                    // If the character is not in DLL, then add this
                    // at the end of DLL.
                    if (inDLL[x-'a'] == NULL) {
                        appendNode(&head, &tail, x);
                        // tail is of the prev node as now this node has
                        // been attached so the tail of the previous 
                        // node contains the address of the current node
                        // added.
                        inDLL[x-'a'] = tail;
                    }
                    else // Otherwise remove this character from DLL
                    {
                        removeNode(&head, &tail, inDLL[x-'a']);
                        inDLL[x-'a'] = NULL;
                        // Also mark it as repeated
                        repeated[x-'a'] = true;
                    }
                }
          
                // Add element to output string as this is the last
                // non repeating character till now
                if (head != NULL) ans+=head->a;
                // Add # as mentioned in question as there is no
                // non repeating character till now
                else ans+='#';
            }
            return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
