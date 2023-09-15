class Solution:
    def isHappy(self, n: int) -> bool:
        def next(n: int) -> bool:
            summ = 0
            while n:
                summ += pow(n % 10, 2)
                n //= 10
            return summ

        slow = next(n)
        fast = next(next(n))

        while slow != fast:
            slow = next(slow)
            fast = next(next(fast))

        return slow == 1   