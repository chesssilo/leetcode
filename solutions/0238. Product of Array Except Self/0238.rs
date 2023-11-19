// Time complexity: O(n)
// Space complexity: O(n)
impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![1; n];

        for i in 1..n {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        let mut suffix = 1;
        for i in (0..n - 1).rev() {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        ans
    }
}