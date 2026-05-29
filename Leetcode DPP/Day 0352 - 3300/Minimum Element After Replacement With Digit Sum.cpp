class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=nums[0], d;
        for(int i=0; i<nums.size(); i++) {
            d=0;
            while(nums[i]) {
                d+=nums[i]%10;
                nums[i]/=10;
            }
            mini=min(d, mini);
        }
        
        return mini;
    }
};