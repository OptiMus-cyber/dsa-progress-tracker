class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k==nums.size()) return *max_element(nums.begin(), nums.end());
        if(k==1) {
            unordered_map<int, int> mp;
            for(int i=0; i<nums.size(); i++) {
                mp[nums[i]]++;
            }
            int res=-1;
            for(auto x: mp) {
                if(x.second==1) {
                    res=max(res, x.first);
                }
            }
            return res;
        }
        if(nums[0]==nums.back()) return -1;
        int a=1, b=1;
        for(int i=1; i<nums.size()-1; i++) {
            if(nums[i]==nums[0]) a=0;
            if(nums.back()==nums[i]) b=0;
        }
        if(a==0) return b?nums.back():-1;
        if(b==0) return a?nums[0]:-1;
        return max(nums[0], nums.back());
    }
};