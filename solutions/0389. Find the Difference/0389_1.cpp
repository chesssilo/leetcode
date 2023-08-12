// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    char findTheDifference(const string &s, const string &t) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]--;
        }
        for (char c : t) {
            count[c]++;
        }
        for (auto kv : count) {
            if (kv.second == 1) {
                return kv.first;
            }
        }
        throw 1;
    }
};