class Solution:

    # Using set
    def detectLoop(self, head):
        st,cur = set(),head
        while cur and not cur in st:
            st.add(cur)
            cur = cur.next
        return True if cur else False

    #Floyd loop detection algorithm
    def detectLoop(self, head):
        #code here
        tortoise, rabbit = head,head
        while rabbit and rabbit.next:
            tortoise = tortoise.next
            rabbit = rabbit.next.next
            if tortoise==rabbit: return True
        return False