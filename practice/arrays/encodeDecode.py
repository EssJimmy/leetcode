from typing import List

class Solution:
    def encode(self, strs: List[str]) -> str:
        return "".join(str(len(s)) + "/" + s for s in strs)

    def decode(self, s : str) -> List[str]:
        ans = []

        i = 0
        while i < len(s):
            slash = s.find("/", i)
            length = int(s[i:slash])
            i = slash + length + 1
            ans.append(s[slash + 1:i])

        return ans



inp =  [""]
dec = Solution().encode(inp)

print(dec)
print(Solution().decode(dec))
