import heapq

class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        min_heap = []

        for x, y in points:
            dist = (x**2) + (y**2)
            min_heap.append([dist, x, y])

        heapq.heapify(min_heap)

        res = []
        for _ in range(k):
            dist, x, y = heapq.heappop(min_heap)
            res.append([x, y])

        return res
    

def main() -> None:
    s = Solution()
    points = [[2,2],[2,2],[3,3],[2,-2],[1,1]]
    k = 4

    print(s.kClosest(points, k))


if __name__ == "__main__":
        main()
