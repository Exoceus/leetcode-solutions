class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        return self.naive(g,s)
    
    # blind
    def naive(self, g, s):
        g.sort()
        s.sort()

        content = 0
        j = 0
        length = len(g)

        for cookie in s:
            if not j < length:
                return content
            if cookie >= g[j]:
                content += 1
                j += 1
        
        return content
