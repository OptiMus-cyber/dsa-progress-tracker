class Solution {
public:
    int solve(int i, int j, int c, vector<vector<int>>& coins, vector<vector<vector<int>>> &dp) {
        int m=coins.size();
        int n=coins[0].size();
        if(i==(m-1)&&j==(n-1)) return c?max(coins[i][j], 0):coins[i][j];
        if(dp[i][j][c]!=INT_MIN) return dp[i][j][c];
        int r=INT_MIN;
        if(i<(m-1)) r=max(coins[i][j]+solve(i+1, j, c, coins, dp), solve(i+1, j, c-1, coins, dp));
        int d=INT_MIN;
        if(j<(n-1)) d=max(coins[i][j]+solve(i, j+1, c, coins, dp), solve(i, j+1, c-1, coins, dp));
        return dp[i][j][c]=max(r, d);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return solve(0, 0, 2, coins, dp);
    }
};