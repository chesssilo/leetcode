// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int firstUniqChar(string_view s) {
        vector<int> count(26);

        for (const char c : s)
            ++count[c - 'a'];

        for (int i = 0; i < s.length(); ++i)
            if (count[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};