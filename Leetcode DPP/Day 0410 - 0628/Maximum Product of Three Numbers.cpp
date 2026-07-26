class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int res=1;
        for(int i=0; i<3; i++) {
            res*=nums[i];
        }
        int res2=nums[0];
        reverse(nums.begin(), nums.end());
        return max(res, res2*nums[0]*nums[1]);
    }
};