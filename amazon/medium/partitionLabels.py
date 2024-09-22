class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        last_index = {}
        ans = []
        size, end = 0, 0

        for i, c in enumerate(s):
            last_index[c] = i

        for i, c in enumerate(s):
            size += 1
            end = max(end, last_index[c])

            if i == end:
                ans.append(size)
                size = 0

        return ans


def main() -> None:
    s = "ababcbacadefegdehijhklij"

    solve = Solution()
    print(solve.partitionLabels(s))


if __name__ == "__main__":
    main()
