class Solution:
    def topKFrequent(self, words: list[str], k: int) -> list[int]:
        frequency = {}

        for w in words:
            if w not in frequency:
                frequency[w] = 0

            frequency[w] += 1

        sorted_freq = sorted(frequency, key=lambda x:(-frequency[x], x))

        return sorted_freq[:k]
    

def main() -> None:
    words = ["i","love","leetcode","i","love","coding"]
    k = 3
    
    s = Solution()
    print(s.topKFrequent(words, k))


if __name__ == "__main__":
    main()
