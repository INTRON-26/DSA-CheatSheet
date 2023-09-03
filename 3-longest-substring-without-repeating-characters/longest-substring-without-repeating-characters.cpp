#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<int,int> m;
        int p1 = 0,p2 = 0,res = 0;
        while(p2 < n){
            m[s[p2]]++;
            while(m[s[p2]]>1){
                m[s[p1]]--;
                p1++;
            }
            res = max(res,p2-p1+1);
            p2++;
        }
        return res;
    }
};