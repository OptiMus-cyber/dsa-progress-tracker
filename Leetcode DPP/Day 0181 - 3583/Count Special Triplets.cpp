class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod=1e9+7;
        unordered_map<int, int> l, r;
        for(int i=1; i<nums.size(); i++) r[nums[i]]++;
        l[nums[0]]++;
        long long cnt=0;
        for(int i=1; i<nums.size()-1; i++) {
            r[nums[i]]--;
            cnt=(cnt+1ll*l[nums[i]*2]*r[nums[i]*2])%mod;
            l[nums[i]]++;
        }
        return cnt;
    }
};