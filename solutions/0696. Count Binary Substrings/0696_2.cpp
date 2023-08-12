// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int countBinarySubstrings(const string &s) {
        int count = 0;
        int prevSize = 0;
        int curSize = 0;
        int curC = '$';
        for (char c : s) {
            if (c == curC) {
                curSize++;
            } else {
                count += min(prevSize, curSize);
                prevSize = curSize;
                curC = c;
                curSize = 1;
            }
        }
        count += min(prevSize, curSize);
        return count;
    }
};