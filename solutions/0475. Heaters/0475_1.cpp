// Time complexity: O((n + m) * log(m))
// Space complexity: O(1)
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int house : houses) {
            int minDist = INT_MAX;
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            if (it != heaters.end()) {
                int heater = *it;
                minDist = min(minDist, abs(heater - house));
            }
            if (it != heaters.begin()) {
                --it;
                int heater = *it;
                minDist = min(minDist, abs(heater - house));
            }
            ans = max(ans, minDist);
        }
        return ans;
    }
};