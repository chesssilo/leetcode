// Time complexity: O(n)
// Space complexity: O(n)
var maxFrequencyElements = function(nums) {
  const count = new Map();

  for (let num of nums)
    count.set(num, (count.get(num) || 0) + 1);

    const maxCount = Math.max(...count.values());
    let ans = 0;

    for (let value of count.values())
      if (value === maxCount)
        ans += value;

    return ans;    
};