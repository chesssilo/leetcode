// Time complexity: O(n)
// Space complexity: O(1)
var validPalindrome = function(s) {
    let l = 0;
    let r = s.length - 1;
  
    while (l < r) {
        if (s[l] !== s[r]) {
            return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
        }
        l++;
        r--;
    }
  
    return true;

    function isPalindrome(s, left, right) {
        while (left < right) {
            if (s[left] !== s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};