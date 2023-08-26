# Time complexity: O(nk), where n=∣strs∣ and k=∣strs[i]∣
# Space complexity: O(n)
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = {}
        for word in strs:
            counts = [0] * 26
            for char in word:
                counts[ord(char) - ord('a')] += 1
            key = tuple(counts)
            if key not in result:
                result[key] = []
            result[key].append(word)

        return result.values()