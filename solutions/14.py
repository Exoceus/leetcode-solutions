class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        return self.naive(strs)

    # blind
    def naive(self, strs):
        prefix = ""

        for i in range(len(strs[0])):
            letter = strs[0][i]
            for word in strs:
                if len(word) <= i or word[i] != letter:
                    return prefix
            
            prefix += letter
        
        return prefix
