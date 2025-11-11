class Solution {
public:
    int solve(int idx, int m, int n, vector<pair<int, int>>& arr,  vector<vector<vector<int>>>& dp) {
        if(m==0 && n==0) return 0;
        if(m<0||n<0) return -1;
        if(idx==arr.size()) return 0;
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        int pick=1+solve(idx+1, m-arr[idx].first, n-arr[idx].second, arr, dp);
        int notPick=solve(idx+1, m, n, arr, dp);
        return dp[idx][m][n]=max(pick, notPick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ones, zeros;
        vector<pair<int, int>> arr;
        for(auto s: strs) {
            ones=0, zeros=0;
            for(auto c: s) {
                if(c=='0') zeros++;
                else ones++;
            }
            arr.push_back({zeros, ones});
        }
        vector<vector<vector<int>>> dp(arr.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0, m, n, arr, dp);
    }
};