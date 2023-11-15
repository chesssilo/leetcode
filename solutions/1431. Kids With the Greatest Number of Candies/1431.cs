// Time complexity: O(n)
// Space complexity: O(n)
public class Solution {
    public IList<bool> KidsWithCandies(int[] candies, int extraCandies) {
        List<bool> ans = new List<bool>();
        int maxCandy = 0;

        foreach(int candy in candies) {
            maxCandy = Math.Max(candy, maxCandy);
        }

        foreach(int candy in candies) {
            ans.Add(candy + extraCandies >= maxCandy);
        }

        return ans;
    }    
}