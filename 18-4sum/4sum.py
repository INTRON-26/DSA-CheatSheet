from collections import Counter
class Solution:
    def fourSum(self, arr: List[int], k1: int) -> List[List[int]]:
        
        ans = list()
        res = set()
        n = len(arr)
        arr.sort()
        for i in range(n-3):
            for j in range(i+1,n-2):
                l = j+1
                r = n-1
                target = k1 - (arr[i]+arr[j])
                while(l<r):
                    sum = arr[l] + arr[r]
                    if(arr[l] + arr[r] == target):
                        res.add( tuple( sorted( (arr[i],arr[j],arr[l],arr[r]) ) ) )
                        l+=1
                        r-=1
                    elif sum < target:
                        l+=1
                    else:
                        r-=1
        print(res)
        for i in res:
            temp =[]
            for k in i:
                temp.append(k)
            ans.append(temp)
        return ans
                
            

        