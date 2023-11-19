// Time complexity: O(sort)
// Space complexity: O(sort)
impl Solution {
    pub fn reduction_operations(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut ans = 0;
        let mut up = 0;

        for i in 1..nums.len() {
            if nums[i] != nums[i - 1] {
                up += 1;
            }
            ans += up;
        }
        return ans;
    }
}