// Time complexity: O(n)
// Space complexity: O(1)
var hasCycle = function(head) {
  slow = head
  fast = head

  while (fast && fast.next) {
      slow = slow.next;
      fast = fast.next.next;

      if (slow === fast) return true;
  }
  return false;
};