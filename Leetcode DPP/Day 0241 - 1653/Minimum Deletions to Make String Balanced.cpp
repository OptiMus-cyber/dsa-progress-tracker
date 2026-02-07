class Solution {
public:
    int solve(int i, bool f, string &s, vector<vector<int>> &dp) {
        if(i==s.size()) {
            return 0;
        }
        if(dp[i][f]!=-1) return dp[i][f];
        int mini=INT_MAX;
        if(s[i]=='a') {
            if(f) mini=min(mini, 1+solve(i+1, f, s, dp));
            else mini=min(mini, solve(i+1, f, s, dp));
        } else {
            if(!f) mini=min(mini, 1+solve(i+1, f, s, dp));
            mini=min(mini, solve(i+1, true, s, dp));
        }
        return dp[i][f]=mini;
    }
    int minimumDeletions(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(2, -1));
        return solve(0, false, s, dp);
    }
};