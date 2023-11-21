// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int countNicePairs(const vector<int>& nums) {
        vector<int> arr;
        unordered_map<int, int> dic;
        int ans = 0;
        constexpr int MOD = 1'000'000'007;

        for (int i = 0; i < nums.size(); ++i) {
            arr.push_back(nums[i] - rev(nums[i]));
        }
        
        for (int num : arr) {
            ans = (ans + dic[num]) % MOD;
            dic[num]++;
        }
        
        return ans;
    }
private:   
    int rev(int num) {
        int result = 0;
        while (num > 0) {
            result = result * 10 + num % 10;
            num /= 10;
        }
        
        return result;
    }
};