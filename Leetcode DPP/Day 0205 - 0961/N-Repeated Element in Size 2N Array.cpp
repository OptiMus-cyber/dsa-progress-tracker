class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) {
            if(mp.count(nums[i])) return nums[i];
            mp[nums[i]]++;
        }
        return 0;
    }
};