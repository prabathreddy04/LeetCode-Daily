   class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        result = 0
        for i in range(31):
            count = 0
            for k in candidates:
                if k & (1 << i):
                    count += 1
            result = max(result, count)
        return result
