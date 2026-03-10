class Solution {
public:
    int mod=1e9+7;
    int solve(int z, int o, int &l, int f, vector<vector<vector<int>>> &dp) {
        if(z==0&&o==0) return 1;
        if(dp[z][o][f]!=-1) return dp[z][o][f];
        long long cnt=0;
        if(f) {
            for(int i=0; i<min(o, l); i++) {
                cnt+=solve(z, o-i-1, l, 0, dp);
            }
        } else {
            for(int i=0; i<min(z, l); i++) {
                cnt+=solve(z-i-1, o, l, 1, dp);
            }
        }
        return dp[z][o][f]=cnt%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<array<long,2>>> dp(
            zero+1, vector<array<long,2>>(one+1, {0LL,0LL}));

        for (int i = 1; i <= min(zero,limit); i++) dp[i][0][0] = 1;
        for (int j = 1; j <= min(one, limit); j++) dp[0][j][1] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                long over0 = (i-limit >= 1) ? dp[i-limit-1][j][1] : 0;
                long over1 = (j-limit >= 1) ? dp[i][j-limit-1][0] : 0;
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] - over0 + MOD) % MOD;
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1] - over1 + MOD) % MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};