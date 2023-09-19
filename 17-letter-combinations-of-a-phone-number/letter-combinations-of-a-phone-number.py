class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if  len(digits) == 0:
            return []
        else:
            nums = {
                '2':'abc',
                '3':'def',
                '4':'ghi',
                '5':'jkl',
                '6':'mno',
                '7':'pqrs',
                '8':'tuv',
                '9':'wxyz'
            }
            res = ['']
            for x in digits:
                temp = []
                for z in nums[x]:
                    for i in res:
                        temp+=[i+z]
                res = temp
            return temp