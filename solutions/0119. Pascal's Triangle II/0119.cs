// Time complexity: O(rowIndex^2)
// Space complexity: O(rowIndex)
public class Solution {
    public IList<int> GetRow(int rowIndex) {
        List<int> ans = new List<int>(rowIndex + 1);
        
        for (int i = 0; i <= rowIndex; i++) {
            ans.Add(1);
        }
        
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                ans[j] += ans[j - 1];
            }
        }
        
        return ans;
    }
}
