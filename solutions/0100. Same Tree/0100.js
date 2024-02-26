// Time complexity: O(n)
// Space complexity: O(h)
var isSameTree = function(p, q) {
  if (!p || !q) 
    return p === q;
  return p.val === q.val &&
         isSameTree(p.left, q.left) &&
         isSameTree(p.right, q.right);    
};