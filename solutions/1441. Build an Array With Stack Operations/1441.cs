// Time complexity: O(mn)
// Space complexity: O(m)
public class Solution {
    public IList<string> BuildArray(int[] target, int n) {
        List<string> ans = new List<string>();
        int i = 0;

        foreach (int num in target)
        {
            while (i < num - 1)
            {
                ans.Add("Push");
                ans.Add("Pop");
                i++;
            }

            ans.Add("Push");
            i++;
        }

        return ans;
    }
}