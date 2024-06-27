# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def numOfMinutes(self, n: int, headID: int, manager: List[int], 
                   informTime: List[int]) -> int:
    def dfs(i: int, headID: int, manager: List[int], informTime: List[int], 
            mem: Dict[int, int]) -> int:
      if i in mem:
        return mem[i]
      if i == headID:
        return 0
      parent = manager[i]
      mem[i] = informTime[parent] + dfs(parent, headID, manager, informTime, 
                                        mem)
      return mem[i]

    ans = 0
    mem = {}
    for i in range(n):
      ans = max(ans, dfs(i, headID, manager, informTime, mem))

    return ans