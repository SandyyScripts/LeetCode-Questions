class Solution(object):
    def matrixScore(self, grid):
        ROWS,COLS = len(grid),len(grid[0])
        
        #FLIP THE ROWS
        for r in range(ROWS):
            if grid[r][0] == 0:
                for c in range(COLS):
                    grid[r][c] = 0 if grid[r][c] else 1
        
        #FLIP THE COLUMNS
        for c in range(COLS):
            one_count = 0
            for r in range(ROWS):
                one_count += grid[r][c]
            if one_count < ROWS - one_count:
                for r in range(ROWS):
                    grid[r][c] = 0 if grid[r][c] else 1
        
        #CALCULATING THE SUM
        ans = 0
        for r in range(ROWS):
            for c in range(COLS):
                ans += grid[r][c]<<(COLS - c -1)
                    
        return ans
                    
        