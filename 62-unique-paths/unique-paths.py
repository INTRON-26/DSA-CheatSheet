class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[-1 for i in range(n)] for x in range(m)]
        def helper(i,j):
            if(i<=0 or j<=0):
                return 1
            if(dp[i][j]!=-1):
                return dp[i][j]
            dp[i][j] = helper(i-1,j) + helper(i,j-1)
            return dp[i][j]
        return helper(m-1,n-1)