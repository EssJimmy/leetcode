from typing import List

class Solution:
    def __checkAnagram(self, str1: str, str2: str) -> bool:
        if len(str1) != len(str2):
            return False
        
        for ch in set(str1):
            if str1.count(ch) != str2.count(ch):
                return False
        
        return True


    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        visited = set()
        ans = []

        for i in range(len(strs)):
            if not strs[i] in visited:
                aux = [strs[i]]
                visited.add(strs[i])
                for j in range(i+1, len(strs)):
                    if self.__checkAnagram(strs[i],strs[j]):
                        aux.append(strs[j])
                        visited.add(strs[j])

                ans.append(aux)

        return ans
