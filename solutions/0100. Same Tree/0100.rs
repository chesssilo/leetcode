// Time complexity: O(n)
// Space complexity: O(h)
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
  pub fn is_same_tree(
    p: Option<Rc<RefCell<TreeNode>>>,
    q: Option<Rc<RefCell<TreeNode>>>
  ) -> bool {
    p == q
  }
}