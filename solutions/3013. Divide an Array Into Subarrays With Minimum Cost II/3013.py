# Time complexity: O(nlogn)
# Space complexity: O(n)
from sortedcontainers import SortedList

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        window_sum = sum(nums[i] for i in range(1, dist + 2))
        selected = SortedList(nums[i] for i in range(1, dist + 2))
        candidates = SortedList()

        def balance() -> int:
            nonlocal window_sum
            while len(selected) < k - 1:
                min_candidate = candidates[0]
                window_sum += min_candidate
                selected.add(min_candidate)
                candidates.remove(min_candidate)
            while len(selected) > k - 1:
                max_selected = selected[-1]
                window_sum -= max_selected
                selected.remove(max_selected)
                candidates.add(max_selected)

            return window_sum      

        window_sum = balance()
        min_window_sum = window_sum

        for i in range(dist + 2, len(nums)):
            out_of_scope = nums[i - dist - 1]
            if out_of_scope in selected:
                window_sum -= out_of_scope
                selected.remove(out_of_scope)
            else:
                candidates.remove(out_of_scope)
            if nums[i] < selected[-1]:
                window_sum += nums[i]
                selected.add(nums[i])
            else:
                candidates.add(nums[i])
            window_sum = balance()
            min_window_sum = min(min_window_sum, window_sum)

        return nums[0] + min_window_sum