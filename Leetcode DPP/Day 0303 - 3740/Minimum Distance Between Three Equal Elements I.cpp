class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i]==nums[j]) {
                    for(int k=j+1; k<nums.size(); k++) {
                        if(nums[j]==nums[k]) {
                            mini=min(mini, 2*k-2*i);
                        }
                    }
                }
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};