// Time complexity: O(logn)
// Space complexity: O(1)
public class Solution {
    public int SearchInsert(int[] nums, int target) {
        int l = 0;
        int r = nums.Length;

        while(l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
}