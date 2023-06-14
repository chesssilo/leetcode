// Time complexity: O(n^2)
// Space complexity: O(1)
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int[] V = { };
        for (int i = 0; i < nums.Length; i++) {
            for (int j = 0; j < nums.Length; j++) {
                if (i != j) {
                    if (nums[i] + nums[j] == target) {
                        return new int[] { i, j };
                    }
                }
            }
        }
        return V;
    }
}