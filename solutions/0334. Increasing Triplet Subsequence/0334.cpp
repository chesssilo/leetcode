// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool increasingTriplet(const vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (const int num : nums) {
            if (num <= first) {
                first = num;
            } else if (num <= second){
                second = num;
            } else {
                return true;
            }
        }
        return false;
    }
};