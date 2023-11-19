class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0, n = arr.size();
        for(int i = 0;i<n;i++) {
            auto temp = 0;
            for(int j = i;j<n;j++) {
                temp+=arr[j];
                if((j-i+1) %2 == 1) {
                    res+=temp;
                }
                
            }
        }
        return res;
    }
};