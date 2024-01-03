// Time complexity: O(mn)
// Space complexity: O(1)
class Solution {
public:
    int numberOfBeams(const vector<string>& bank) {
        int ans = 0;
        int prev = 0;

        for (string s : bank) {
            int count = 0;
            for (char c : s) {
                if (c == '1') {
                    count++;
                }
            }
            if (count != 0) {
                ans += (prev * count);
                prev = count;
            }
        }

        return ans;
    }
};