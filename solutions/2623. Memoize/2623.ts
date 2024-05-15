// Time Complexity: O(1) or O(f(n))
// Space Complexity: O(n)
type Fn = (...params: number[]) => number;

function memoize(fn: Fn): Fn {
  const cache: Record<string, number> = {};
  return function (...args) {
    const key = args.join(' ');
    return cache[key] === undefined ? (cache[key] = fn(...args)) : cache[key];
  };
}