class Solution:
    def next_day(self, cells: list[int]) -> list[int]:
        new_cell = [0] * 8

        for i in range(1, 7):
            if cells[i-1] == cells[i+1]:
                new_cell[i] = 1

        return new_cell
    
    def prisonAfterNDays(self, cells: list[int], n: int) -> list[int]:
        found_dict = {}

        for i in range(n):
            c = tuple(cells)
            if c in found_dict:
                length_loop = i - found_dict[c]

                return self.prisonAfterNDays(cells, (n-i) % length_loop)
            else:
                found_dict[c] = i
                cells = self.next_day(cells)
        
        return cells
    

def main():
    cells = [1,0,0,1,0,0,1,0]
    n = 1000000000

    s = Solution()
    print(s.prisonAfterNDays(cells, n))


if __name__ == "__main__":
    main()
