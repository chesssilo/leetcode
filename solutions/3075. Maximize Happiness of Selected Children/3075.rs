// Time complexity: O(nlogn)
// Space complexity: O(n)
use std::cmp::max;

impl Solution {
  pub fn maximum_happiness_sum(mut happiness: Vec<i32>, k: i32) -> i64 {
    happiness.sort();
    happiness.reverse();
    *&happiness[0..k as usize].iter()
    .enumerate()
    .map(|(i, x)| max(0, *x as i64 - i as i64)).sum()
  }
}