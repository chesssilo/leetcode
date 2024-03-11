// Time complexity: O(n+m)
// Space complexity: O(n)
var intersection = function(nums1, nums2) {
  let ans = [];
  let set = new Set(nums1);
  
  for (const num of nums2)
    if (set.has(num)) {
      ans.push(num);
      set.delete(num);
    }

  return ans;  
};