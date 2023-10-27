// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    string longestPalindrome(const string &s) {
        int ans[2] = {0, 0};
        
        for (int i = 0; i < s.length(); i++) {
            int oddLength = expand(i, i, s);
            if (oddLength > ans[1] - ans[0] + 1) {
                int dist = oddLength / 2;
                ans[0] = i - dist;
                ans[1] = i + dist;
            }
            
            int evenLength = expand(i, i + 1, s);
            if (evenLength > ans[1] - ans[0] + 1) {
                int dist = (evenLength / 2) - 1;
                ans[0] = i - dist;
                ans[1] = i + 1 + dist;
            }
        }

        int i = ans[0];
        int j = ans[1];
        return s.substr(i, j - i + 1);
    }
    
private:
    int expand(int i, int j, const string &s) {
        int left = i;
        int right = j;
        
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }
};