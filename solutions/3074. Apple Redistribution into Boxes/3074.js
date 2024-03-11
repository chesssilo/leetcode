// Time complexity: O(n+mlogm)
// Space complexity: O(1)
var minimumBoxes = function(apple, capacity) {
  let sum = apple.reduce((acc, curr) => acc + curr, 0);
  let i = 0;
  capacity.sort((a, b) => b - a);

  for (; i < capacity.length && sum > 0; ++i)
    sum -= capacity[i];

  return i;    
};