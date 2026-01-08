class Solution {
public:
    int solve(int i, int j, bool f, vector<int>& nums1, vector<int>& nums2, vector<vector<vector<int>>> &dp) {
        if(i==nums1.size()||j==nums2.size()) {
            if(!f) return INT_MIN;
            return 0;
        }
        if(dp[i][j][f]!=-1) return dp[i][j][f];
        int maxi=INT_MIN;
        maxi=max(maxi, nums1[i]*nums2[j]+solve(i+1, j+1, true, nums1, nums2, dp));
        maxi=max(maxi, solve(i+1, j, f, nums1, nums2, dp));
        maxi=max(maxi, solve(i, j+1, f, nums1, nums2, dp));
        return dp[i][j][f]=maxi;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<vector<int>>> dp(nums1.size(), vector<vector<int>> (nums2.size(), vector<int>(2, -1)));
        return solve(0, 0, false, nums1, nums2, dp);
    }   
};