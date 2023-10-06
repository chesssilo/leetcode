// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> majorityElement(const vector<int>& nums) {
        unordered_map<int,int> count;
        vector<int> ans;
        int maxValue = nums.size() / 3;

        for (const int num : nums) {
            count[num]++;
        }
        
        for (const auto& pair : count) {
            if (pair.second > maxValue) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};