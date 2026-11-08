class Solution:
    def convert(self, s: str, numRows: int) -> str:
        word_len = len(s)
        if word_len <= numRows or numRows == 1:
            return s
        
        out = ""
        # think of each straight vertical line + diagonal as a single unit. The jump from character on a particular character on the vertical line to the next one on vertical line is fixed
        jump = (numRows - 1) * 2

        for i in range(numRows):
            j = i

            while j < word_len:
                out += s[j]

                if i != 0 and i != numRows - 1:
                    # for the "middle rows" (not top or bottom), we also get a character from the diagonal
                    diag = j + ((numRows - i - 1) * 2)
                    if diag < word_len:
                        out += s[diag]    
            
                j += jump

        # O(n), n = len of string
        # O(1) space
        
        return out
    
    
# Alternative approach is just to go through linear scan and append character to the appropriate row sublist. But that is O(n) space