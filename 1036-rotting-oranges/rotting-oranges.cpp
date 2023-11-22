class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0, cnt = 0,total = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        int X[4] = {0,0,1,-1}, Y[4] = {1,-1,0,0};
        while(!q.empty()) {
            int k = q.size();
            cnt+=k;
            for(int i = 0;i<k;i++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0;i<4;i++) {
                    int a,b;
                    a = x+X[i];
                    b = y+Y[i];
                    if(a<0 || b<0 || a>=m || b>=n || grid[a][b]!=1) continue;
                    else{
                        grid[a][b] = 2;
                        q.push({a,b});
                    }
                }
            }
                if(!q.empty()) res++;
        }
            return total == cnt ? res: -1;
    }
};