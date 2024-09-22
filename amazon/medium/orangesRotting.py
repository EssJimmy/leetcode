from collections import deque

class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        q = deque()
        m, n = len(grid), len(grid[0])
        ans, fresh = 0, 0

        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];

        for i in range(m):
            for j in range(n):
                match grid[i][j]:
                    case 1:
                        fresh += 1
                        
                    case 2:
                        q.append((i, j))

                    case _:
                        continue

        while q and fresh > 0:
            
            for i in range(len(q)):
                r, c = q.popleft()
                
                for dr, dc in directions:
                    row, col = r + dr, c + dc
                    
                    if row < 0 or row == m or col < 0 or col == n or grid[row][col] != 1:
                        continue

                    grid[row][col] = 2
                    q.append((row, col))
                    fresh -= 1

            ans += 1
        
        return ans if fresh == 0 else -1
    