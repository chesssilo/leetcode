# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def defangIPaddr(self, address: str) -> str:
    i = 0
    while i < len(address):
      if address[i] == '.':
        address = address[:i] + '[' + address[i] + ']' + address[i+1:]
        i+= 2
      i += 1

    return address    