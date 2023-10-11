// Time complexity: O(n)
// Space complexity: O(h)
public class Solution {
    public bool IsBalanced(TreeNode root) {
        return GetHeight(root) != -1;
    }

    private int GetHeight(TreeNode node) {
        if (node == null) {
            return 0;
        }  
        int leftH = GetHeight(node.left);
        if (leftH == -1) {
            return -1;
        }
        int rightH = GetHeight(node.right);
        if (rightH == -1) {
            return -1;
        }
        if (Math.Abs(leftH - rightH) > 1) {
            return -1;
        } else {
            return Math.Max(leftH, rightH) + 1;
        } 
    }
}