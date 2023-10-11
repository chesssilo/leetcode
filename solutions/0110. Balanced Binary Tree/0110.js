// Time complexity: O(n)
// Space complexity: O(h)

var isBalanced = function(root) {
    return getHeight(root) !== -1;
}

function getHeight(node) {
    if (node === null) {
        return 0;
    }
    const leftH = getHeight(node.left);
    if (leftH === -1) {
        return -1;
    }
    const rightH = getHeight(node.right);
    if (rightH === -1) {
        return -1;
    }
    if (Math.abs(leftH - rightH) > 1) {
        return -1;
    } else {
        return Math.max(leftH, rightH) + 1;
    }
}