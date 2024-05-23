# Time complexity: O(loghigh)
# Space complexity: O(loghigh)
class Solution:
  def sequentialDigits(self, low: int, high: int) -> List[int]:
    ans = []
    q = collections.deque([num for num in range(1, 10)])

    while q:
      num = q.popleft()
      if num > high:
        return ans
      if low <= num and num <= high:
        ans.append(num)
      last_digit = num % 10
      if last_digit < 9:
        q.append(num * 10 + last_digit + 1)

    return ans