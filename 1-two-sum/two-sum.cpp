class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        map<int,int> m;
        for(int i = 0;i<n;i++) {
            int key = target - nums[i];
            if(m.find(key) != m.end()) {
                ans[0] = m[key];
                ans[1] =  i;
                break;
            } else {
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};