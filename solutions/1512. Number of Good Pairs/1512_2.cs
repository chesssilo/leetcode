// Time complexity: O(n)
// Space complexity: O(n)
public class Solution {
    public int NumIdenticalPairs(int[] nums) {
        Dictionary<int, int> counts = new Dictionary<int, int>();
        int ans = 0;
        
        foreach (int num in nums) {
            if (counts.ContainsKey(num)) {
                ans += counts[num];
                counts[num]++;
            }
            else {
                counts[num] = 1;
            }
        }
        
        return ans;
    }
}