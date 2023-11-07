// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool wordPattern(const string &pattern, const string &str) {
        const int n = pattern.length();
        istringstream iss(str);
        vector<int> charToIndex(128);
        unordered_map<string, int> stringToIndex;

        int i = 0;
        for (string word; iss >> word; ++i) {
            if (i == n) {
                return false;
            }
            if (charToIndex[pattern[i]] != stringToIndex[word]) {
                return false;
            }
            charToIndex[pattern[i]] = i + 1;
            stringToIndex[word] = i + 1;
        }

        return i == n;
    }
};