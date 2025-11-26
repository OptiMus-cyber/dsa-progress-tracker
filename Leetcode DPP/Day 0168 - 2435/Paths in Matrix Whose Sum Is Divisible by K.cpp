class Solution {
public:
    int mod=1e9+7;
    void solve(int i, int j, int& k, vector<vector<int>>& grid, vector<pair<int, int>>& del, vector<vector<vector<long long>>>& dp, vector<vector<bool>>& vis) {
        int m=grid.size();
        int n=grid[0].size();
        if(vis[i][j]) {
            return;
        }
        if(i==(m-1)&&j==(n-1)) {
            dp[i][j][grid[i][j]%k]++;
            vis[i][j]=true;
            return;
        } 
        for(auto u: del) {
            int x=i+u.first;
            int y=j+u.second;
            if(x>=0 && y>=0 && x<m && y<n) {
                solve(x, y, k, grid, del, dp, vis);
                for(int l=0; l<k; l++) {
                    if(dp[x][y][l]) {
                        dp[i][j][(l+grid[i][j])%k]=(dp[i][j][(l+grid[i][j])%k]+dp[x][y][l])%mod;
                    }
                }
            }
        }
        vis[i][j]=true;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<pair<int, int>> del= {{0, 1}, {1, 0}};
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(k, 0)));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        solve(0, 0, k, grid, del, dp, vis);
        return dp[0][0][0];
    }
};