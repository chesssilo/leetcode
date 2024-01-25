// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int maxFrequencyElements(const vector<int>& nums) {
        unordered_map<int, int> count;
        int maxCount = 0;
        int ans = 0;
        
        for (const int num : nums)
            ++count[num];
        
        for (const auto& pair : count)
            maxCount = max(maxCount, pair.second);
            
        for (const auto& pair : count)
            if (pair.second == maxCount) 
                ans += pair.second;    
            
        return ans;     
    }
};