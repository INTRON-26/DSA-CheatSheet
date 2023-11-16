class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int z = 0,l = 0, r= 0;
        for(r = 0;r<n;r++) {
            if(nums[r] == 0) z++;
            if(z>1) {
                if(nums[l] == 0) z--;
                l+=1;
            }
        }
        return r-l-1;
    }
};