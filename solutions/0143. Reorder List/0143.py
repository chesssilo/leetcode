class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        center_ptr = slow.next
        slow.next = None

        left, right = None, center_ptr
        while right:
            tmp = right.next
            right.next = left
            left, right = right, tmp

        first, second = head, left
        while first and second:
            tmp_first = first.next
            tmp_second = second.next
            first.next = second
            second.next = tmp_first
            first = tmp_first
            second = tmp_second      
        