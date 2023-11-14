// Time complexity: O(n + m)
// Space complexity: O(n + m)
class Solution {
public:
    string mergeAlternately(string_view word1, string_view word2) {
        string ans ="";
        int n = word1.length();
        int m = word2.length();
        int i = 0;
        int j = 0;
        while (i < n || j < m) {
            if ( i < n) {
                ans.push_back(word1[i++]);
            }
            if ( j < m) {
                ans.push_back(word2[j++]);
            }
        }
        return ans;
    }
};