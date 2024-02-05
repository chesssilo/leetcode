// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int returnToBoundaryCount(const vector<int>& nums) {
        int count = 0;
        int pos = 0;
        
        for (int num : nums) {
            pos += num;
            if (pos == 0) {
                ++count;
            }
        }
        
        return count;
    }
};