class Solution {
public:
    bool check(vector<int>& nums) {
        int f=1;
        for(int i=1; i<nums.size(); i++) {
            if(f) {
                if(nums[i]<nums[i-1]) {
                    if(nums[i]>nums[0]) return false;
                    f=0;
                }
            } else {
                if(nums[i]<nums[i-1]||nums[i]>nums[0]) return false;
            }
        }
        return true;
    }
};