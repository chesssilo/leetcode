// Time complexity: O(n)
// Space complexity: O(n)
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> numToIndex = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; ++i) {
            if (numToIndex.ContainsKey(target - nums[i])) {
                return new int[] { numToIndex[target - nums[i]], i };
            }
            numToIndex[nums[i]] = i;
        }
        throw new Exception("No two numbers sum to the target.");
    }
}