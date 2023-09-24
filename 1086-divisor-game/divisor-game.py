import math
class Solution:
    dp = [False for i in range(1001)]
    def __init__(self):
        self.dp[1] = False
        self.dp[2] = True
        for i in range(3,1001):
            for j in range(1,int(math.sqrt(i))+1):
                if(i%j == 0 and self.dp[i-j] == False):
                    self.dp[i] = True
                    break
         

    def divisorGame(self, n: int) -> bool:
        return self.dp[n]