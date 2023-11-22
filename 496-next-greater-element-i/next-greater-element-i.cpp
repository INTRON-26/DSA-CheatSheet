class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        map<int,int> m;
        for(int i = 0;i<n2;i++) m[arr2[i]] = i;
        vector<int> res(n2,-1);
        stack<int> st;
        for(int i = n2-1;i>=0;i--) {
            while(!st.empty() && st.top()<=arr2[i]) st.pop();
            if(st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(arr2[i]);
        }
        for(int i = 0;i<n1;i++) {
            arr1[i] = res[m[arr1[i]]];
        }
        return arr1;
    }
};