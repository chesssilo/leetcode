// Time complexity: O(n)
// Space complexity: O(n)
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let mut count: HashMap<i32, i32> = HashMap::new();
        let mut unique: HashSet<i32> = HashSet::new();

        for a in arr {
            *count.entry(a).or_insert(0) += 1;
        }

        for (_, &value) in &count {
            if !unique.insert(value) {
                return false;
            }
        }

        true
    }
}