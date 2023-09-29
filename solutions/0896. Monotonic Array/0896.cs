// Time complexity: O(n)
// Space complexity: O(1)
public class Solution {
    public bool IsMonotonic(int[] nums) {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < nums.Length; ++i) {
            increasing &= nums[i] >= nums[i - 1];
            decreasing &= nums[i] <= nums[i - 1];
        }

        return increasing || decreasing;
    }
}