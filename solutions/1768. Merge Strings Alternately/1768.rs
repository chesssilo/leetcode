// Time complexity: O(n + m)
// Space complexity: O(n + m)
impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let mut ans = String::new();
        let n = word1.len();
        let m = word2.len();
        let mut i = 0;
        let mut j = 0;
        while i < n || j < m {
            if i < n {
                ans.push(word1.chars().nth(i).unwrap());
                i += 1;
            }
            if j < m {
                ans.push(word2.chars().nth(j).unwrap());
                j += 1;
            }
        }
        ans
    }
}