class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res=nums[0];
        sort(nums.begin()+1, nums.end());
        return res+nums[1]+nums[2];
    }
};