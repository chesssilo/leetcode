// Time complexity: O(n)
// Space complexity: O(n)
use std::rc::Rc;
use core::cell::RefCell;
use std::collections::HashMap;

type TreeNodeS = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
  fn find_mode(root: TreeNodeS) -> Vec<i32> {
    let mut count_map: HashMap<i32, i32> = HashMap::new();
    let mut max_streak = 0;

    Self::traverse(&root, &mut count_map, &mut max_streak);

    let mut ans: Vec<i32> = Vec::new();
    for (val, streak) in count_map {
      if streak == max_streak {
        ans.push(val);
      }
    }

    ans
  }

  fn traverse(node: &TreeNodeS, count_map: &mut HashMap<i32, i32>, 
              max_streak: &mut i32) {
    if let Some(node) = node {
      let borrowed_node = node.borrow();
      *count_map.entry(borrowed_node.val).or_insert(0) += 1;
      *max_streak = (*max_streak).max(count_map[&borrowed_node.val]);

      Self::traverse(&borrowed_node.left, count_map, max_streak);
      Self::traverse(&borrowed_node.right, count_map, max_streak);
    }
  }
}