use std::rc::Rc;
use std::cell::RefCell;
use std::cmp;

impl Solution {
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 0;
        Self::max_depth(&root, &mut ans);
        ans
    }

    fn max_depth(root: &Option<Rc<RefCell<TreeNode>>>, ans: &mut i32) -> i32 {
        match root {
            None => 0,
            Some(node) => {
                let l = Solution::max_depth(&node.borrow().left, ans);
                let r = Solution::max_depth(&node.borrow().right, ans);
                *ans = cmp::max(*ans, l + r);
                1 + cmp::max(l, r)
            }
        }
    }    
}
