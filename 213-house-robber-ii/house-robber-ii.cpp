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
        if(n == 1) {
            return nums[0];
        }
        if(n == 0) return 0;
        vector<int> dp1(n,-1),dp2(n,-1);
        vector<int> a(n-1),b(n-1);
        for(int i = 0;i<n-1;i++) {
            a[i] = nums[i];
        }
        for(int i=1;i<n;i++) {
            b[i-1] = nums[i];
        }
        return max(fun(n-2,a,n-1,dp1),fun(n-2,b,n-1,dp2));
    }
};