class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0,r = height.size()-1;
        int res = 0;
        while(l<r) {
            int temp = min(height[l],height[r])*(r-l);
            res = max(res,temp);
            if(height[r] > height[l]) l++;
            else r--;
        }
        return res;
    }
};