// Time complexity: O(n)
// Space complexity: O(1)
var maximumOddBinaryNumber = function(s) {
  const zeros = (s.match(/0/g) || []).length;
  const ones = s.length - zeros;
  return '1'.repeat(ones - 1) + '0'.repeat(zeros) + '1';
};