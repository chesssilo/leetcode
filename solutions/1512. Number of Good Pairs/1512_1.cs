// Time complexity: O(n^2)
// Space complexity: O(1)
public class Solution {
    public int NumIdenticalPairs(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.Length; ++i) {
            for (int j = i + 1; j < nums.Length; ++j) {
                if (nums[i] == nums[j]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
}