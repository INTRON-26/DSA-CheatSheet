class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), res = n-1;
        for(int i = n-1;i>=0;i--) {
            if(i+nums[i] >= res)
                res = i;
        }
        return res == 0;
    }
};