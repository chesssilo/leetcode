// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(128);

        for (const char c : s)
            ++count[c];

        for (const char c : t)
            if (--count[c] < 0)
                return c;

        throw;
    }
};