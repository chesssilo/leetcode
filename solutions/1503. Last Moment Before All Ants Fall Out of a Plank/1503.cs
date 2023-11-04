// Time complexity: O(n + m)
// Space complexity: O(1)
public class Solution {
    public int GetLastMoment(int n, int[] left, int[] right) {
        int ans = 0;

        foreach (int num in left) {
            ans = Math.Max(ans, num);
        }
        
        foreach (int num in right) {
            ans = Math.Max(ans, n - num);
        }
        
        return ans;
    }
}