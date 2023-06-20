# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result = []

        for num in range(1,n+1):
            word = ""

            if (num % 3 == 0):
                word += "Fizz"
            if (num % 5 == 0):
                word += "Buzz"
            if not word:
                word = str(num)

            result.append(word)  

        return result                 