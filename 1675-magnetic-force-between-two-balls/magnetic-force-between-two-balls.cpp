class Solution {
public:
    bool fun(vector<int> &arr,int dist,int m) {
        int cnt = 1,temp = arr[0];
        for(int i = 1;i<arr.size();i++) {
            if(arr[i] - temp >= dist) {
                cnt++;
                temp = arr[i];
            }
            if(cnt>=m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& arr, int m) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int l = 1,h = arr[n-1]-arr[0];
        while(l<=h) {
            int mid = (h-l)/2+l;
            if(fun(arr,mid,m)) l = mid+1;
            else h = mid-1;
        }
        return h;
    }
};