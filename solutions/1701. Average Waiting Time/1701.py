# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def averageWaitingTime(self, customers: List[List[int]]) -> float:
    wait = 0
    curr = 0

    for customer in customers:
      curr = max(curr, 1.0 * customer[0]) + customer[1]
      wait += curr - customer[0]

    return 1.0 * wait / len(customers)