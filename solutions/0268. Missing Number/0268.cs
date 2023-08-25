// Time complexity: O(n)
// Space complexity: O(1)
public class Solution {
    public int MissingNumber(int[] nums) {
        var sum = nums.Sum();

        return nums.Length * (nums.Length + 1) / 2 - sum;
    }
}