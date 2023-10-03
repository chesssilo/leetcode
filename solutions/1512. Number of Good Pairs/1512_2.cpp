// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int numIdenticalPairs(const vector<int>& nums) {
        unordered_map<int, int> counts;
        int ans = 0;
        
        for (const int num: nums) {
            ans += counts[num];
            counts[num]++;
        }
        
        return ans;
    }
};