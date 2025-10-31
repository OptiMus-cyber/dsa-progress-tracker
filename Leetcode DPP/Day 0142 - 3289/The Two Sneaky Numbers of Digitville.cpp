class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i=0; i<n; i++) {
            if(mp.count(nums[i])) res.push_back(nums[i]);
            if(res.size()==2) return res;
            mp[nums[i]]++;
        }
        return res;
    }
};