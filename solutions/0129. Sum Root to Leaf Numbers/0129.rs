// Time complexity: O(n)
// Space complexity: O(h)
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
  pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    let mut ans = 0;
    Self::dfs(&root, 0, &mut ans);
    ans
  }

  fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, path: i32, ans: &mut i32) {
    if let Some(node) = root {
      let node = node.borrow();
      if node.left.is_none() && node.right.is_none() {
        *ans += path * 10 + node.val;
        return;
      }
      Self::dfs(&node.left, path * 10 + node.val, ans);
      Self::dfs(&node.right, path * 10 + node.val, ans);
    }
  }
}