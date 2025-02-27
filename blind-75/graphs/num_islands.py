
class Solution:

    def __init__(self):
        i = 0

    def numIslands(self, matrix: list[list]) -> int:
        visited = set()

        count = self.__numIslands(matrix, visited, 0, 0)

        return count

    def __numIslands(self, matrix: list[list], visited: set, row: int, column: int):
        oob = (column < 0) or (row < 0) or (column > len(matrix[0])-1) or (row > len(matrix)-1)
        if ((row, column) in visited) or oob:
            return 0
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[row][column] == "1" and (row, column) not in visited:
                    visited.add((row, column))

                    count = self.__numIslands(matrix, visited, row+1, column)
                    count = self.__numIslands(matrix, visited, row-1, column)
                    count = self.__numIslands(matrix, visited, row, column+1)
                    count = self.__numIslands(matrix, visited, row, column-1)

        count += 1

        return count

def main():
    mat = [["1", "0", "1", "0", "1", "0"], ["1", "0", "1", "0", "1", "0"], 
           ["1", "0", "1", "0", "1", "0"]]
    
    s = Solution()

    print(s.numIslands(mat))


if __name__ == "__main__":
    main()
