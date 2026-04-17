class Solution {
public:
    int rev(int x) {
        int res=0;
        while(x) {
            res=res*10+(x%10);
            x/=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        int res=INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            int y=rev(nums[i]);
            // cout<<y<<endl;
            if(mp.count(y)==0) {
                mp[nums[i]].push_back(i);
                continue;
            }
            int x=lower_bound(mp[y].begin(), mp[y].end(), i)-mp[y].begin();
            if(x==mp[y].size()) res=min(res, i-mp[y][x-1]);
            else if(mp[y][x]==i) {
                return 0;
            } else {
                if(x!=0) res=min(res, i-mp[y][x-1]); 
                res=min(res, mp[y][x]-i); 
            }
            mp[nums[i]].push_back(i);
        }
        return (res==INT_MAX)?-1:res;
    }
};