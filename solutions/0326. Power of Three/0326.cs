// Time complexity: O(1)
// Space complexity: O(1)
public class Solution {
    public bool IsPowerOfThree(int n) {
        return n > 0 && Math.Pow(3, 19) % n == 0;
    }
}