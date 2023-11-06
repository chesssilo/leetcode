// Time complexity: O(n)
// Space complexity: O(1)
public class Solution {
    public bool ValidPalindrome(string s) {
        for (int l = 0, r = s.Length - 1; l < r; ++l, --r) {
            if (s[l] != s[r]) {
                return ValidPalindrome(s, l + 1, r) || ValidPalindrome(s, l, r - 1);
            }
        } 
        return true;
    }

    private bool ValidPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
}