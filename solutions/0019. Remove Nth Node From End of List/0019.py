# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    slow = head
    fast = head

    for _ in range(n):
      fast = fast.next

    if not fast:
      return fast.next

    while right.next:
      slow = slow.next
      fast = fast.next
    slow.next = slow.next.next

    return head