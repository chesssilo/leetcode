// Time complexity: O(n)
// Space complexity: O(1)
public class Solution {
    public int[] SortArrayByParity(int[] nums) {
        int[] ans = new int[nums.Length];
        int evenIndex = 0;
        int oddIndex = nums.Length - 1;

        foreach (int num in nums) {
            if (num % 2 == 0) {
                ans[evenIndex] = num;
                evenIndex++;
            } else {
                ans[oddIndex] = num;
                oddIndex--;
            }
        }
        return ans;
    }
}