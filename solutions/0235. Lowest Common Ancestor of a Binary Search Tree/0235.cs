// Time complexity: O(h)
// Space complexity: O(h)
public class Solution {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (p.val < root.val && q.val < root.val)
            return LowestCommonAncestor(root.left, p, q);
        if (p.val > root.val && q.val > root.val)
            return LowestCommonAncestor(root.right, p, q);
        return root;
    }
}