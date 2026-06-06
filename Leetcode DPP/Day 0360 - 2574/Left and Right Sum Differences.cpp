class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l=0, r=accumulate(nums.begin(), nums.end(), 0);
        for(int i=0; i<nums.size(); i++) {
            r-=nums[i];
            ans[i]=abs(l-r);
            l+=nums[i];
        }
        return ans;
    }
};