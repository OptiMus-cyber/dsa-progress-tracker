class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int s=k;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>s) {
                return s;
            } else if(nums[i]==s) s+=k;
        }
        return s;
    }
};