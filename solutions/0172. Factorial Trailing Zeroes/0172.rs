// Time complexity: O(logn)
// Space complexity: O(1)
impl Solution {
    pub fn trailing_zeroes(mut n: i32) -> i32 {
        let mut ans = 0;

        while (n > 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
}