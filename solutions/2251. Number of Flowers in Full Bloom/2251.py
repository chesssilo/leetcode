# Time complexity: O((n+m)logn)
# Space complexity: O(n+m)
class Solution:
  def fullBloomFlowers(
    self, flowers: List[List[int]], people: List[int]
  ) -> List[int]:
    starts = sorted(s for s, _ in flowers)
    ends = sorted(e for _, e in flowers)
    return [bisect.bisect_right(starts, person) -
            bisect.bisect_left(ends, person)
            for person in people]