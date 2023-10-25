// Time complexity: O(n)
// Space complexity: O(n)
public class Solution {
    public int KthGrammar(int n, int k) {
        string binaryString = Convert.ToString(k - 1, 2);
        int count = binaryString.Replace("0", "").Length;
        return count % 2 == 0 ? 0 : 1;
    }
}