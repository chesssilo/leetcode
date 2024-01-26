# Time complexity: O(∣s∣+∣a∣+∣b∣)
# Space complexity: O(∣s∣+∣a∣+∣b∣)
class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:
        ans = []
        indices_a = self._kmp(s, a)
        indices_b = self._kmp(s, b)
        indices_b_index = 0

        for i in indices_a:
            while indices_b_index < len(indices_b) and indices_b[indices_b_index] - i < -k:
                indices_b_index += 1
            if indices_b_index < len(indices_b) and indices_b[indices_b_index] - i <= k:
                ans.append(i)

        return ans

    def _kmp(self, s: str, pattern: str) -> List[int]:
        def getLPS(s: str) -> List[int]:
            lps = [0] * len(s)
            j = 0
            for i in range(1, len(s)):
                while j > 0 and s[j] != s[i]:
                    j = lps[j - 1]
                if s[i] == s[j]:
                    lps[i] = j + 1
                    j += 1

            return lps

        lps = getLPS(pattern)
        res = []
        i = 0
        j = 0
        while i < len(s):
            if s[i] == pattern[j]:
                i += 1
                j += 1
            if j == len(pattern):
                res.append(i - j)
                j = lps[j - 1]            
            elif i < len(s) and s[i] != pattern[j]:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1

        return res