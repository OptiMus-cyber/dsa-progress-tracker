class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int k, vector<vector<vector<int>>>& dp) {
        int m=grid.size();
        int n=grid[0].size();
        if(k<0) return INT_MIN;
        if(i==(m-1)&&j==(n-1)) {
            if(k-(grid[i][j]?1:0)>=0) return grid[i][j];
            else return INT_MIN;
        }
        if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];
        int r=INT_MIN;
        if(j<(n-1)) r=grid[i][j]+solve(i, j+1, grid, k-(grid[i][j]?1:0), dp);
        int d=INT_MIN;
        if(i<(m-1)) d=grid[i][j]+solve(i+1, j, grid, k-(grid[i][j]?1:0), dp);
        return dp[i][j][k]=max(r, d);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, INT_MIN)));
        int res=solve(0, 0, grid, k, dp);
        if(res<0) return -1;
        return res;
    }
};