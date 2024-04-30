# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def isValidSudoku(self, board: List[List[int]]) -> bool:
    seen = set()

    for i in range(len(board)):
      for j in range(len(board[0])):
        c = board[i][j]
        if c == '.':
          continue
        if c + '@row' + str(i) in seen or \
           c + '@col' + str(j) in seen or \
           c + '@box' + str(i // 3) + str(j // 3) in seen:
          return False
        seen.add(c + '@row' + str(i))
        seen.add(c + '@col' + str(j))
        seen.add(c + '@box' + str(i // 3) + str(j // 3))

    return True    