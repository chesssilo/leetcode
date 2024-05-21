// Time complexity: O(1)
// Space complexity: O(1)
class Calculator {
  private curr: number;

  constructor(value: number) {
    this.curr = value;
  }

  add(value: number): Calculator {
    this.curr += value;
    return this;
  }

  subtract(value: number): Calculator {
    this.curr -= value;
    return this;
  }

  multiply(value: number): Calculator {
    this.curr *= value;
    return this;
  }

  divide(value: number): Calculator {
    if (value === 0) throw new Error('Division by zero is not allowed');
    this.curr /= value;
    return this;
  }

  power(value: number): Calculator {
    this.curr **= value;
    return this;
  }

  getResult(): number {
    return this.curr;
  }
}