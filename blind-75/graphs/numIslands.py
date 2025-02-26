class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        self.graph = grid
        rows, cols = len(grid), len(grid[0])

        def dfs(r, c):
            if r < 0 or c < 0 or r == rows or c == cols or self.graph[r][c] in "02":
                return
            
            self.graph[r][c] = "2"
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

        count = 0
        for r in range(rows):
            for c in range(cols):
                if self.graph[r][c] == "1":
                    count += 1
                    dfs(r, c)

        return count