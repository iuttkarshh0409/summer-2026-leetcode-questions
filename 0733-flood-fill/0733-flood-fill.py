class Solution:
    def floodFill(self, image, sr, sc, color):
        original = image[sr][sc]

        # Already the target color
        if original == color:
            return image

        rows = len(image)
        cols = len(image[0])

        def dfs(r, c):
            # Out of bounds
            if r < 0 or r >= rows or c < 0 or c >= cols:
                return

            # Only fill pixels matching the original color
            if image[r][c] != original:
                return

            image[r][c] = color

            # 4 directions
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

        dfs(sr, sc)
        return image