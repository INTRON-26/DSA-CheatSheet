class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> left(n), right(n);
        for(int i = 0;i<n;i++ ) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            right[st.top()] = n;
            st.pop();
        }
        for(int i = n-1;i>=0;i-- ) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }
        int res = 0;
        for(int i= 0;i<n;i++){
            res = max(res,arr[i]*(right[i]-left[i]-1));
        }
        return res;
    }
};