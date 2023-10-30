// Time complexity: O(logn)
// Space complexity: O(logn)
public class Solution {
    public string ConvertToTitle(int columnNumber) {
        StringBuilder ans = new StringBuilder();
        while (columnNumber > 0) {
            columnNumber--;
            ans.Insert(0, (char)('A' + columnNumber % 26));
            columnNumber /= 26;
        }
        return ans.ToString();
    }
}