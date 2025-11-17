class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int idx=-1, n=nums.size();
        for(int i=0; i<n; i++) {
            if(idx!=-1&&nums[i]==1&&i-idx-1<k) return false;
            if(nums[i]) idx=i;
        }
        return true;
    }
};