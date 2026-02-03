class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int c=1;
        if(nums[0]>=nums[1]) return false;
        if(nums[nums.size()-2]>=nums[nums.size()-1]) return false;
        int p=-1, q=nums.size();
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i]>=nums[i+1]) {
                p=i;
                break;
            }
        }
        if(p==-1) return false;
        for(int i=nums.size()-1; i>0; i--) {
            if(nums[i-1]>=nums[i]) {
                q=i;
                break;
            }
        }
        if(q==nums.size()) return false;
        if(p>=q) return false;
        for(int i=p; i<q; i++) {
            if(nums[i]<=nums[i+1]) return false;
        }
        return true;
    }
};