// Time complexity: O(mn)
// Space complexity: O(1)
impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut ans = 0;
        let mut prev = 0;

        for string in bank {
            let count = string.chars().filter(|&c| c == '1').count() as i32;
            if count != 0 {
                ans += (prev * count);
                prev = count;
            }
        }

        ans
    }    
}