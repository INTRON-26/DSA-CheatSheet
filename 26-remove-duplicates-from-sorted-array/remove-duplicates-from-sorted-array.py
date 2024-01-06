class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        mp = dict()
        for i in nums:
            mp[i] = 1
        idx = 0
        for i in mp:
            print(i)
            nums[idx] = i
            idx+=1
        print(nums)
        extra = len(nums) - len(mp)
        while(extra > 0):
            nums.pop()
            extra-=1
        return len(mp)