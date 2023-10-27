// Time complexity: O(n^3)
// Space complexity: O(1)
class Solution {
public:
    string longestPalindrome(const string &s) {
        for (int length = s.length(); length > 0; length--) {
            for (int start = 0; start <= s.length() - length; start++) {
                if (check(start, start + length, s)) {
                    return s.substr(start, length);
                }
            }
        }
        
        return "";
    }
    
private:
    bool check(int i, int j, const string &s) {
        int left = i;
        int right = j - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};