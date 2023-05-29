# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Using while loop
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        cur = None
        while(head):
            next = head.next
            head.next = cur
            cur = head
            head = next
        return cur

# Using recursion concept similar as above
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head: return head
        def recursion(cur,prev):
            next = cur.next
            cur.next = prev
            if not next: return cur
            return recursion(next,cur)
        return recursion(head,None)
    
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head: return head
        def recursion(cur):
            if not cur.next: return cur
            newHead = recursion(cur.next)
            head.next.next = head
            head.next = None
            return newHead
        return recursion(head)