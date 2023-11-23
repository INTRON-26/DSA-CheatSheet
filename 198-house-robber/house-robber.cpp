class Solution {
public:
    int fun(int idx,vector<int> &arr,int n,vector<int> &dp) {
        if(idx == 0) return dp[idx] = arr[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(arr[idx] + fun(idx-2,arr,n,dp),fun(idx-1,arr,n,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return fun(n-1,nums,n,dp);
    }
};