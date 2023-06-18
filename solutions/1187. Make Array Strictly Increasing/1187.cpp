// Time complexity : O(m⋅n⋅log⁡n)
// Space complexity: O(n)
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> dp{{-1, 0}};

        sort(arr2.begin(), arr2.end());

        for (const int a : arr1) {
            unordered_map<int, int> nextDp;
            for (const auto& [val, steps] : dp) {
                if (a > val)
                    nextDp[a] = min(nextDp.count(a) ? nextDp[a] : INT_MAX, steps);
                if (const auto it = upper_bound(arr2.begin(), arr2.end(), val);
                    it != arr2.cend());
                nextDp[*it] = min(nextDp.count(*it) ? nextDp[*it] : INT_MAX, steps + 1);
            }
            if (nextDp.empty())
                return -1;
            dp = move(nextDp);
        }

        int ans = INT_MAX;
        for (const auto& [_, steps] : dp)
            ans = min(ans, steps);
        return ans;
    }
};