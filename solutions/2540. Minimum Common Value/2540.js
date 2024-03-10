// Time complexity: O(n+m)
// Space complexity: O(1)
var getCommon = function(nums1, nums2) {
  let i = 0;
  let j = 0;

  while (i < nums1.length && j < nums2.length) {
    if (nums1[i] == nums2[j])
      return nums1[i]
    if (nums1[i] < nums2[j])
      i += 1;
    else 
      j += 1;        
  }

  return -1;
};