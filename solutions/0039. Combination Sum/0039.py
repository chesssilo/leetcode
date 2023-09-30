class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []

        def dtree(i, combination, residue):
            if residue == 0:
                ans.append(combination.copy())
                return
            if i >= len(candidates) or residue < 0:
                return

            combination.append(candidates[i])
            dtree(i, combination, residue - candidates[i]) 
            combination.pop()
            dtree(i+1, combination, residue)

        dtree(0, [], target)

        return ans