# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result = []

        fizz_buzz_dict = {3 : "Fizz", 5 : "Buzz"}
        
        divisors = [3, 5]

        for num in range(1, n + 1):

            word = []

            for key in divisors:
                if num % key == 0:
                    word.append(fizz_buzz_dict[key])

            if not word:
                word.append(str(num))

            result.append(''.join(word))

        return result