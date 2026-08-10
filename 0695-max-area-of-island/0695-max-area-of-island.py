class Solution:
    def maxAreaOfIsland(self, grid):
        rows = len(grid)
        cols = len(grid[0])

        def dfs(r, c):
            # Out of bounds or water
            if r < 0 or r >= rows or c < 0 or c >= cols:
                return 0

            if grid[r][c] == 0:
                return 0

            # Mark as visited
            grid[r][c] = 0

            # Count this cell + connected land
            return (
                1
                + dfs(r + 1, c)
                + dfs(r - 1, c)
                + dfs(r, c + 1)
                + dfs(r, c - 1)
            )

        max_area = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    area = dfs(r, c)
                    max_area = max(max_area, area)

        return max_area