// Time complexity: O((n + m) * log(m))
// Space complexity: O(1)
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        ranges::sort(houses);
        ranges::sort(heaters);

        int ans = 0;
        int i = 0;

        for (const int house : houses) {
            while (i + 1 < heaters.size() &&
                   house - heaters[i] > heaters[i + 1] - house)
                ++i;
            ans = max(ans, abs(heaters[i] - house));
        }

        return ans;
    }
};