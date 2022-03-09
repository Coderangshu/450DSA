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
	    // both are of length 26(i.e. number of english alphabets)
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


// Same as above just using vector to update the head and tail 
// instead of passing them as reference to the functions
class solution2{
    private:
        struct Node{
            char data;
            Node *next, *prev;
            Node(char val){
                data = val;
                next = prev = nullptr;
            }
        };
        
        vector<Node*> addNode(Node *head, Node *tail, char c){
            if(!head) head = tail = new Node(c);
            else{
                tail->next = new Node(c);
                tail->next->prev = tail;
                tail = tail->next;
            }
            return vector<Node*> {head,tail};
        }
        
        vector<Node*> delNode(Node *head, Node *tail, Node *toDel){
            if(head==tail and head==toDel){
                free(toDel);
                return vector<Node*> {nullptr,nullptr};
            }
            else if(head==toDel) head = head->next;
            else if(tail==toDel) tail = tail->prev;
            else{
                toDel->prev->next = toDel->next;
                toDel->next->prev = toDel->prev;
            }
            free(toDel);
            return vector<Node*> {head,tail};
        }
        
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<bool> repeated(26,false);
		    vector<Node*> address(26,nullptr);
		    Node* head = nullptr, *tail = nullptr;
		    string ans = "";
		    for(auto &c:A){
		        if(!address[c-'a']){
		            auto v = addNode(head,tail,c);
		            head = v[0], tail = address[c-'a'] = v[1];
		        }
		        else{
		            if(!repeated[c-'a']){
		                auto v = delNode(head,tail,address[c-'a']);
		                head = v[0], tail = v[1];
		                repeated[c-'a'] = true;
		            }
		        }
		        ans += head?head->data:'#';
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
