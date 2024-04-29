// Time complexity: O(one*zero*limit)
// Space complexity: O(one*zero)
impl Solution {
  const K_MOD: i64 = 1_000_000_007;

  fn number_of_stable_arrays(zero: i32, one: i32, limit: i32) -> i64 {
    let zero = zero as usize;
    let one = one as usize;
    let limit = limit as usize;

    let mut dp = vec![vec![vec![-1; 2]; zero + 1]; one + 1];
    let a = Self::dfs(zero, one, limit, true, &mut dp) % Self::K_MOD;
    let b = Self::dfs(zero, one, limit, false, &mut dp) % Self::K_MOD;

    (a + b) % Self::K_MOD
}

  fn dfs(zero: usize, one: usize, limit: usize, 
          ms: bool, dp: &mut Vec<Vec<Vec<i64>>>) -> i64 {
    if one == 0 && zero == 0 {
      return 1;
    }

    let mut res = 0;

    if dp[one][zero][ms as usize] != -1 {
      return dp[one][zero][ms as usize];
    }

    if ms {
      for i in 1..=std::cmp::min(one, limit) {
        res += Self::dfs(zero, one - i, limit, false, dp) % Self::K_MOD;
      }
    } else {
      for i in 1..=std::cmp::min(zero, limit) {
        res += Self::dfs(zero - i, one, limit, true, dp) % Self::K_MOD;
      }
    }

    dp[one][zero][ms as usize] = res % Self::K_MOD;
  
    res % Self::K_MOD
  }
}