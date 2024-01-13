// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minSteps(string_view s, string_view t) {
        vector<int> count(26);

        for (const char c : s)
            ++count[c - 'a'];

        for (const char c : t)
            --count[c - 'a'];

        return accumulate(count.begin(), count.end(), 0,
                          [](int subtotal, int c) { return subtotal + abs(c); }) / 2;
    }
};