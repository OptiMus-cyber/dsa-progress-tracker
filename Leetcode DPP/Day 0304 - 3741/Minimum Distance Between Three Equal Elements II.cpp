class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int mini=INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            if(mp.count(nums[i])) {
                mp[nums[i]][0]++;
                if(mp[nums[i]][0]>=3) mini=min(mini, 2*(i+1)-2*(mp[nums[i]][1]+1));
                mp[nums[i]][1]=mp[nums[i]][2];
                mp[nums[i]][2]=i;
            } else {
                mp[nums[i]]={1, i, i};
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};