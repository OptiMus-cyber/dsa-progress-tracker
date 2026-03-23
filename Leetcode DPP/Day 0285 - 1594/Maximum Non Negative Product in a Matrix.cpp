class Solution {
public:
    int mod=1e9+7;
    pair<long long, long long> solve(int i, int j, int &m, int &n, vector<vector<int>>& grid, vector<vector<pair<long long, long long>>> &dp) {
        if(i==(m-1)&&j==(n-1)) {
            return {grid[i][j], grid[i][j]};
        }
        if(dp[i][j].first!=INT_MIN&&dp[i][j].second!=INT_MAX) return dp[i][j];
        long long maxi=INT_MIN, mini=INT_MAX;
        if(i<(m-1)) {
            pair<long long, long long> a=solve(i+1, j, m, n, grid, dp);
            maxi=max({maxi, 1ll*grid[i][j]*a.first, 1ll*grid[i][j]*a.second});
            mini=min({mini, 1ll*grid[i][j]*a.first, 1ll*grid[i][j]*a.second});
        }
        if(j<(n-1)) {
            pair<long long, long long> a=solve(i, j+1, m, n, grid, dp);
            maxi=max({maxi, 1ll*grid[i][j]*a.first, 1ll*grid[i][j]*a.second});
            mini=min({mini, 1ll*grid[i][j]*a.first, 1ll*grid[i][j]*a.second});
        }
        return dp[i][j]={maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n, {INT_MIN, INT_MAX}));
        pair<long long, long long> res=solve(0, 0, m, n, grid, dp);
        if(res.first<0) return -1;
        return res.first%mod;
    }
};