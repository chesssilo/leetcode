// Time complexity: O(n)
// Space complexity: O(n)
class ArrayWrapper {
  private nums: number[];

  constructor(nums: number[]) {
    this.nums = nums;
  }

  valueOf(): number {
    return this.nums.reduce((sum, num) => sum + num, 0);
  }

  toString(): string {
    return '[' + this.nums.join(',') + ']';
  }
}