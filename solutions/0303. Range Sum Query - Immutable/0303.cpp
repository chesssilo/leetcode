// Time complexity: O(n)
// Space complexity: O(n)
class NumArray {
public:
    NumArray(const vector<int>& nums) 
        : prefixSum(nums.size() + 1, 0)
    {    
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) const {
        return prefixSum[right + 1] - prefixSum[left];
    }
private:
    vector<int> prefixSum;
};