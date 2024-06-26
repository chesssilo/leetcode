// Time complexity: O(n)
// Space complexity: O(h)
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
  pub fn bst_to_gst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    fn reversed_inorder(node: &Option<Rc<RefCell<TreeNode>>>, pref: &mut i32) {
      if let Some(n) = node {
        let mut n = n.borrow_mut();

        reversed_inorder(&n.right, pref);

        n.val += *pref;
        *pref = n.val;

        reversed_inorder(&n.left, pref);
      }
    }

    let mut pref = 0;
    reversed_inorder(&root, &mut pref);

    root
  }
}