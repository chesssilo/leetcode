# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def isPalindrome(self, head: Optional[ListNode]) -> bool:
    def reverseList(head: Optional[ListNode]) -> Optional[ListNode]:
      prev = None
      curr = head

      while curr:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next

      return prev    

    slow = head
    fast = head

    while fast and fast.next:
      slow = slow.next
      fast = fast.next.next

    if fast:
      slow = slow.next
    slow = reverseList(slow)

    while slow:
      if slow.val != head.val:
        return False
      slow = slow.next
      head = head.next

    return True