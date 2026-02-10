class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int cnt=0;
        unordered_map<int, int> mp;
        int res=0, n=nums.size();
        for(int i=0; i<n; i++) {
            cnt=0;
            mp={};
            if((n - i) <= res) break;
            for(int j=i; j<n; j++) {
                if(!mp.count(nums[j])) {
                    if(nums[j]%2==0) {
                        cnt++;
                    } else cnt--;
                }
                mp[nums[j]]++;
                if(cnt==0) res=max(res, j-i+1);
            }
        }
        return res;
    }
};