// Time complexity: O(nlogn)
// Space complexity: O(logn)
impl Solution {
    pub fn maximum_element_after_decrementing_and_rearranging(mut arr: Vec<i32>) -> i32 {
        arr.sort();
        let mut ans = 1;
        for i in 1..arr.len() {
            if arr[i] >= ans + 1 {
                ans += 1;
            }
        }
        ans
    }
}