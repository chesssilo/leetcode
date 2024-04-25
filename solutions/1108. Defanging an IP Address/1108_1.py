# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def defangIPaddr(self, address: str) -> str:
    return address.replace('.', '[.]')