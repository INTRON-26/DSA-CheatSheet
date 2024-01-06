class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def fun(s1,open,close,n):
            if(len(s1) == 2*n):
                print(s1)
                res.append(s1)
                return
            if(open<n):
                fun(s1+'(',open+1,close,n)
            if(close<open):
                fun(s1+')',open,close+1,n)
        fun("",0,0,n)
        return res