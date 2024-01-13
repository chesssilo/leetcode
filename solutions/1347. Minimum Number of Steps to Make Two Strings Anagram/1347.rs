// Time complexity: O(n)
// Space complexity: O(1)
impl Solution {
    pub fn min_steps(s: String, t: String) -> i32 {
        let mut counts = [0; 26];

        for byte in s.bytes() {
            counts[(byte - b'a') as usize] += 1;
        }

        for byte in t.bytes() {
            counts[(byte - b'a') as usize] -= 1;
        }

        counts.iter().map(|&count: &i32| count.abs()).sum::<i32>() >> 1
    }
}