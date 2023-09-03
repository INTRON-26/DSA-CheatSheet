class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        idx = 0
        cnt = 1
        ans = ""
        for idx in range(n):
            #odd
            temp = s[idx : idx+1]
            p1 = idx-1
            p2 = idx+1
            while(p1>=0 and p2<n and s[p1]==s[p2]):
                cnt = max(cnt,p2-p1+1)
                if(cnt == p2-p1+1):
                    ans = s[p1 : p2+1]
                p1-=1
                p2+=1
            p1 = idx
            p2 = idx+1
            while(p1>=0 and p2<n and s[p1]==s[p2]):
                cnt = max(cnt,p2-p1+1)
                if(cnt == p2-p1+1):
                    ans = s[p1 : p2+1]
                p1-=1
                p2+=1
        if(cnt == 1):
            return s[0]
        return ans