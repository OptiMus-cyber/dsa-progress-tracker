class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int j=0, l=0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
            while(mp[nums[i]]>k) {
                mp[nums[j++]]--;
            }
            l=max(l, i-j+1);
        }
        return l;
    }
};