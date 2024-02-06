# Time complexity: O(mn)
# Space complexity: O(mn)
class Solution:
    def resultGrid(self, image: List[List[int]], threshold: int) -> List[List[int]]:
        m = len(image)
        n = len(image[0])
        sums = [[0] * n for _ in range(m)]
        counts = [[0] * n for _ in range(m)]

        for i in range(m - 2):
            for j in range(n - 2):
                if self._is_region(image, i , j, threshold):
                    subgrid_sum = sum(image[x][y]
                                        for x in range(i, i + 3)
                                        for y in range(j, j + 3))
                    for x in range(i, i + 3):
                        for y in range(j, j + 3):
                            sums[x][y] += subgrid_sum // 9
                            counts[x][y] += 1

        for i in range(m):
            for j in range(n):
                if counts[i][j] > 0:
                    image[i][j] = sums[i][j] // counts[i][j]

        return image

    def _is_region(self, image: List[List[int]], i: int, j: int, threshold: int) -> bool:
        for x in range(i, i + 3):
            for y in range(j, j + 3):
                if x > i and abs(image[x][y] - image[x - 1][y]) > threshold:
                    return False
                if y > j and abs(image[x][y] - image[x][y - 1]) > threshold:
                    return False
        return True