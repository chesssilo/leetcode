// Time complexity: O(∣order∣+∣s∣)
// Space complexity: O(26)
var customSortString = function(order, s) {
  let ans = '';
  const count = Array(26).fill(0);

  for (const c of s)
    ++count[c.charCodeAt(0) - 'a'.charCodeAt(0)];

  for (const c of order) {
    ans += c.repeat(count[c.charCodeAt(0) - 'a'.charCodeAt(0)]);
    count[c.charCodeAt(0) - 'a'.charCodeAt(0)] = 0;
  }
      
  for (let i = 0; i < 26; i++)
    ans += String.fromCharCode('a'.charCodeAt(0) + i).repeat(count[i]);

  return ans;
};