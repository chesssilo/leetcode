// Time complexity: O(nlogk)
// Space complexity: O(n)
class KthLargest {
    vector<int> nums;
    int k;

public:
    KthLargest(int k, const vector<int>& nums) 
      : k(k)
      , nums(nums)
    {}

    int add(int val) {
        nums.push_back(val);
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }          
};