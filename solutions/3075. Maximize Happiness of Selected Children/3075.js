// Time complexity: O(nlogn)
// Space complexity: O(1)
var maximumHappinessSum = function(happiness, k) {
  happiness.sort((a, b) => b - a);
  let count = 0;
  let sum = 0;

  for (let i = 0; i < k; ++i) {
    if (happiness[i] - count < 0)
      return sum;

    sum += happiness[i] - count;
    ++count;    
  }

  return sum;
};