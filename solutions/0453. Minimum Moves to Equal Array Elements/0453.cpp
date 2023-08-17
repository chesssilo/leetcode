// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minMoves(const vector<int>& nums) {
        int minNum = INT_MAX;
        for (int num : nums) {
            minNum = min(minNum, num);
        }
        int sum = 0;
        for (int num : nums) {
            sum += num - minNum;
        }
        return sum;
    }
};