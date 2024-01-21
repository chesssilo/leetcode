# Time complexity: O(n^2)
# Space complexity: O(1)
class Solution:
    def beautifulSubstrings(self, s: str, k: int) -> int:
        ans = 0
        n = len(s)

        for i in range(n):
            vowels = 0
            consonants = 0
            for j in range(i, n):
                if self.is_vowel(s[j]):
                    vowels += 1
                else:
                    consonants += 1

                if vowels == consonants and (vowels * consonants) % k == 0:
                    ans += 1

        return ans

    def is_vowel(self, c: str) -> bool:
        return c in ['a', 'e', 'i', 'o', 'u']