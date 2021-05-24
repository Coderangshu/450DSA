/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* middleNode(ListNode* head) {
        ListNode *tortoise = head, *rabbit = head;
        int i=1;
        while(1!=0){
            // If length is 1
            if(rabbit->next==nullptr) break;
            // If length is 2
            if(rabbit->next->next==nullptr){
                i++;
                break;
            }
            rabbit = rabbit->next->next;
            i+=2;
            tortoise = tortoise->next;
            // If odd then next is NULL
            if(rabbit->next==nullptr) break;
            // If even then next to next is NULL
            if(rabbit->next->next==nullptr){
                i++;
                break;
            }
        }
        if(i%2==1) return tortoise;
        else return tortoise->next;
    }
};
