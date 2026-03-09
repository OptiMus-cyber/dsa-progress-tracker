class Solution {
public:
    int mod=1e9+7;
    int solve(int zero, int one, int f, int &l, vector<vector<vector<int>>> &dp) {
        if(zero==0&&one==0) return 1;
        if(dp[zero][one][f]!=-1) return dp[zero][one][f];
        long long cnt=0;
        if(f) {
            for(int i=0; i<min(zero, l); i++) {
                cnt=(cnt+solve(zero-i-1, one, 0, l, dp))%mod;
            }
        } else {
            for(int i=0; i<min(one, l); i++) {
                cnt=(cnt+solve(zero, one-i-1, 1, l, dp))%mod;
            }
        }
        return dp[zero][one][f]=cnt%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>> (one+1, vector<int>(2, -1)));
        return (solve(zero, one, 0, limit, dp)+solve(zero, one, 1, limit, dp))%mod;
    }
};