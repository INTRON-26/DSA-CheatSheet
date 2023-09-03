class Solution {
public:
    int mySqrt(int x) {
        int l = 1, h = x;
        if(x == 0) return 0;
        int ans;
        while(l<=h){
            long mid = (h-l)/2 + l;
            if(mid*mid == x) return mid;
            else if(mid*mid < x) {
                ans = mid;
                l = mid+1;
            }
            else h = mid-1;
        }
        return ans;
    }
};