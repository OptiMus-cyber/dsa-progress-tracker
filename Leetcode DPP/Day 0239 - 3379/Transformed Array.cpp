class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> res=nums;
        for(int i=0; i<nums.size(); i++) {
            int mod=abs(nums[i])%nums.size();
            if(nums[i]==0) {
                res[i]=nums[i];
            } else if(nums[i]>0) {
                if((nums.size()-i-1)>=mod) {
                    res[i]=nums[mod+i];
                } else {
                    res[i]=nums[mod+i-nums.size()];
                }
            } else {
                if((i)>=mod) {
                    res[i]=nums[i-mod];
                } else {
                    res[i]=nums[nums.size()-(mod-i)];
                }
            }
        }
        return res;
    }
};