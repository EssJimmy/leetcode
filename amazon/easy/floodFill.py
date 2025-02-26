class Solution:
    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        if image[sr][sc] == color:
            return image
        
        m, n = len(image), len(image[0])
        original_color = image[sr][sc]
        visited = set()
        
        def dfs(r, c):
            if (r, c) in visited or r < 0 or r == m or c < 0 or c == n or image[r][c] != original_color:
                return
            
            image[r][c] = color
            visited.add((r, c))
            directions = [[0,1], [0,-1], [1,0], [-1,0]]

            for dr, dc in directions:
                dfs(r+dr, c+dc)

        dfs(sr, sc)
        return image
