class Solution:
    def mostCommonWord(self, paragraph: str, banned: list[str]) -> str:
        symbols = "!?',;."
        word_count = {}
        banned_set = set(banned)
        
        paragraph = paragraph.lower()
        for s in symbols:
            paragraph = paragraph.replace(s, " ")

        word_list = paragraph.split()
        for word in list(word_list):
            if word in banned_set:
                word_list.remove(word)
            else:
                if word in word_count:
                    word_count[word] += 1
                else:
                    word_count[word] = 1

        max_word = word_list[0].lower()
        max_value = word_count[max_word]
        for k, v in word_count.items():
            if max_value < v:
                max_value = v
                max_word = k
        
        return max_word


def main() -> None:
    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    banned = ["hit"]

    s = Solution()

    print(s.mostCommonWord(paragraph, banned))


if __name__ == "__main__":
    main()
