class Solution {
public:
    int solve(int i, int &k, vector<int>& arr, vector<int> &dp) {
        if(dp[i]!=-1) return dp[i];
        int ans=0, n=arr.size();
        for(int j=i+1; j<=min(i+k, n-1); j++) {
            if(arr[j]>=arr[i]) break;
            ans=max(ans, 1+solve(j, k, arr, dp));
        }
        for(int j=i-1; j>=max(i-k, 0); j--) {
            if(arr[j]>=arr[i]) break;
            ans=max(ans, 1+solve(j, k, arr, dp));
        }
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans=0;
        vector<int> dp(arr.size(), -1);
        for(int i=0; i<arr.size(); i++) {
            ans=max(ans, 1+solve(i, d, arr, dp));
        }
        return ans;
    }
};