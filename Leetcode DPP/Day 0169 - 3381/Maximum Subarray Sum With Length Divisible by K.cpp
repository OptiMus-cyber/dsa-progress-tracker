class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long sum=0, res=LONG_LONG_MIN, n=nums.size();
        vector<long long> ans(n, 0);
        for(int i=0; i<n; i++) {
            sum+=nums[i];
            if(i-k+1>=0) {
                if(i-k>=0) {
                    ans[i]=max({sum, ans[i-k]+sum});
                } else {
                    ans[i]=sum;
                }
                res=max(res, ans[i]);
                sum-=nums[i-k+1];
            }
        }
        return res;
    }
};