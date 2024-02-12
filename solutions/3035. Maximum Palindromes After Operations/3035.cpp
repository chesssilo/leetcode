// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int maxPalindromesAfterOperations(const vector<string>& words) {
        int count[26] = {};
        int pairs = 0;
        int ans = 0;
        vector<int> lengths;

        for (string_view word : words) {
            for (const char c : word) {
                pairs += (++count[c - 'a']) % 2 == 0;
            }
            lengths.push_back(word.length());
        }

        ranges::sort(lengths);

        for (int length : lengths) {
            pairs -= length / 2;
            ans += pairs >= 0;
        }

        return ans;
    }
};