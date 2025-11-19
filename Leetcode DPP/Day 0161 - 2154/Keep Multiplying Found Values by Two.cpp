class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(original==nums[i]) original*=2;
            else if(original<nums[i]) return original;
        }
        return original;
    }
};