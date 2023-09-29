// Time complexity: O(n)
// Space complexity: O(n)
public class Solution {
    public int[] SortArrayByParity(int[] nums) {
        int[] ans = new int[nums.Length];
        int index = 0;

        foreach (int num in nums) {
            if (num % 2 == 0) {
                ans[index++] = num;
            }
        }

        foreach (int num in nums) {
            if (num % 2 != 0) {
                ans[index++] = num;
            }
        }

        return ans;
    }
}