// Time complexity: O(n)
// Space complexity: O(1)
public class Solution {
    public int FindUnsortedSubarray(int[] nums) {
        int maxi = nums[0];
        int last = -1;

        for (int i = 0; i < nums.Length; ++i) {
            maxi = Math.Max(maxi, nums[i]);
            if (nums[i] < maxi) {
                last = i;
            } 
        }

        if (last == -1) {
            return 0;
        }

        int mini = nums[nums.Length - 1];
        int first = -1;
        for (int i = nums.Length - 1; i >= 0; --i) {
            mini = Math.Min(mini, nums[i]);
            if (nums[i] > mini) {
                first = i;
            }
        }

        return last - first + 1;
    }
}
