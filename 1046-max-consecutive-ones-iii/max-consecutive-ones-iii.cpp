class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, z = 0,res = 0, n= nums.size();
        for (int r= 0;r<n;r++) {
            if(nums[r] == 0) {
                z++;
            }
            while(z>k) {
                if(nums[l] == 0) z--;
                l++;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};