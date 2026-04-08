class Solution {
public:
    int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        for(int i=0; i<q.size(); i++) {
            for(int j=q[i][0]; j<=q[i][1]; j+=q[i][2]) {
                nums[j]=(1ll*nums[j]*q[i][3])%mod;
            }
        }
        int res=0;
        for(int i=0; i<nums.size(); i++) {
            res^=nums[i];
        }
        return res;
    }
};