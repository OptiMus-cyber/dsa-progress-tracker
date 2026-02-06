class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int j=0, res=INT_MAX;
        for(int i=0; i<n; i++) {
            while(1ll*nums[j]*k<nums[i]) {
                j++;
            }
            res=min(res, n-(i-j+1));
        }
        return res;
    }
};