class Solution(object):
    def countPaths(self, grid):
        mod = 10**9 + 7
        n = len(grid)
        m = len(grid[0])
        dp = [[-1 for _ in range(m)] for _ in range(n)]
        
        def solve(row, col, grid, prev, dp):
            if row < 0 or col < 0 or row >= len(grid) or col >= len(grid[0]) or prev >= grid[row][col]:
                return 0
            if dp[row][col] != -1:
                return dp[row][col]
            
            dp[row][col] = 1
            r = solve(row, col+1, grid, grid[row][col], dp)
            l = solve(row, col-1, grid, grid[row][col], dp)
            u = solve(row-1, col, grid, grid[row][col], dp)
            d = solve(row+1, col, grid, grid[row][col], dp) 
            dp[row][col] += r + l + u + d
            return dp[row][col]
        
        ans = 0
        for row in range(n):
            for col in range(m):
                ans += solve(row, col, grid, -1, dp)
        
        return ans % mod
