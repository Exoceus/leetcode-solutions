class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        col_present = [0] * cols
        row_present = [0] * rows

        # key idea is that once we increment the row and col present, future servers know that they can communicate w/ prev server. But first server in row and col, won't know. So just keep track of that
        missed = []

        total = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    row_present[i] += 1
                    col_present[j] += 1

                    if row_present[i] > 1 or col_present[j] > 1:
                        total += 1
                    else:
                        missed.append((i,j))
        
        # simpler solution is just to maintain missing lint and instead just do full 2nd pass and increment total only if row/ col _present is >= 2 when encountering a server 
        for i, j in missed:
            if row_present[i] > 1 or col_present[j] > 1:
                total += 1
        
        # Time complexity: O(n * m + j), n = rows, m = cols, j = # of unique servers on unique row and col
        
        return total