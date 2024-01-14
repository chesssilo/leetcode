// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool closeStrings(string_view word1, string_view word2) {
        if (word1.length() != word2.length())
            return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (const char c : word1)
            ++count1[c - 'a'];

        for (const char c : word2)
            ++count2[c - 'a'];

        for (int i = 0; i < 26; ++i)
            if ((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0))
                return false;

        ranges::sort(count1);
        ranges::sort(count2);
        
        return count1 == count2;
    }
};