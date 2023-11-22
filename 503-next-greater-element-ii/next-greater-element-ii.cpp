class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i  = 2*n-1;i>=0;i--) {
            while(!st.empty() && st.top()<=arr[i%n]) {
                st.pop();
            }
            if(i<n) {
                if(!st.empty()) {
                    res[i] = st.top();
                }
                else res[i] = -1;
            }
            st.push(arr[i%n]);
        }
        return res;
    }
};