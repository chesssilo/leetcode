// Time complexity: O(n)
// Space complexity: O(h)
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
  pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut ans = vec![];
    Self::postorder(&mut ans, root);
    
    ans
  }

  fn postorder(ans: &mut Vec<i32>, root: Option<Rc<RefCell<TreeNode>>>) {
    if let Some(node) = root {
      Self::postorder(ans, node.borrow().left.clone());
      Self::postorder(ans, node.borrow().right.clone());
      ans.push(node.borrow().val);
    }
  }
}