class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long s1=0, s2=0, res=INT_MAX, n=nums.size();
        for(int i=0; i<nums.size(); i++) s2=(s2+nums[i])%p;
        unordered_map<int, int> mp;
        for(long long i=0; i<nums.size(); i++) {
            if(s2%p==0) res=min(res, i);
            if(mp.count(s2%p)) {
                res=min(res, i-mp[s2%p]-1);
            }
            s1=(s1+nums[i])%p;
            s2=(p+s2-nums[i]%p)%p;
            mp[(p-s1)%p]=i;
            if(s1%p==0) res=min(res, 1ll*n-i-1);
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};