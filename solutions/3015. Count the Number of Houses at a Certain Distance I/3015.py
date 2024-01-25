# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        if x > y:
            x, y = y, x

        def both_in_ring(ring_len: int) -> List[int]: 
            res = [0] * n
            for k in range(1, (ring_len - 1) // 2 + 1):
                res[k - 1] += ring_len
            if ring_len % 2 == 0:
                res[ring_len // 2 - 1] += ring_len // 2

            return res

        def both_in_the_same_line(line_len: int) -> List[int]:
            res = [0] * n
            for k in range(1, line_len + 1):
                res[k - 1] += line_len - k

            return res

        def line_to_ring(line_len: int, ring_len: int) -> List[int]:
            res = [0] * n
            for k in range(1, line_len + ring_len):
                max_in_ring_len = min(k - 1, ring_len // 2)
                min_in_ring_len = max(0, k - line_len)
                if min_in_ring_len <= max_in_ring_len:
                    res[k - 1] += (max_in_ring_len - min_in_ring_len + 1) * 2
                    if min_in_ring_len == 0:
                        res[k - 1] -= 1
                    if max_in_ring_len * 2 == ring_len:
                        res[k - 1] -= 1  

            return res

        def line_to_line(left_line_len: int, right_line_len: int) -> List[int]:
            res = [0] * n
            for k in range(left_line_len + right_line_len + 2):
                max_in_left = min(left_line_len, k - 1 -(x < y))
                min_in_left = max(1, k - right_line_len - (x < y))
                if min_in_left <= max_in_left:
                    res[k - 1] += max_in_left - min_in_left + 1

            return res        

        ring_len = y - x + 1
        left_line_len = x - 1
        right_line_len = (n - y)

        ans = [0] * n
        ans = list(map(operator.add, ans, both_in_ring(ring_len)))
        ans = list(map(operator.add, ans, both_in_the_same_line(left_line_len)))
        ans = list(map(operator.add, ans, both_in_the_same_line(right_line_len)))
        ans = list(map(operator.add, ans, line_to_ring(left_line_len, ring_len)))
        ans = list(map(operator.add, ans, line_to_ring(right_line_len, ring_len)))
        ans = list(map(operator.add, ans, line_to_line(left_line_len, right_line_len)))

        return [freq * 2 for freq in ans]   