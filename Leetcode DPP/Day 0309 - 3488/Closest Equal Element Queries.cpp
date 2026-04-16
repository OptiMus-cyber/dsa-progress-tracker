class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& q) {
        vector<int> res(q.size(),-1);
        unordered_map<int, vector<int>> mp;
        int m=nums.size();
        for(int i=0; i<m; i++) {
            mp[nums[i]].push_back(i);
        }
        for(int i=0; i<q.size(); i++) {
            if(mp.count(nums[q[i]])&&mp[nums[q[i]]].size()>1) {
                int x=lower_bound(mp[nums[q[i]]].begin(), mp[nums[q[i]]].end(), q[i])-mp[nums[q[i]]].begin();
                res[i]=INT_MAX;
                int n=mp[nums[q[i]]].size();
                if(x==n-1) res[i]=min({mp[nums[q[i]]][x]-mp[nums[q[i]]][x-1], mp[nums[q[i]]][0]+m-mp[nums[q[i]]][x]});
                else if(x==0) res[i]=min({mp[nums[q[i]]][x]+m-mp[nums[q[i]]][n-1], mp[nums[q[i]]][x+1]-mp[nums[q[i]]][x]});
                else res[i]=min({mp[nums[q[i]]][x]-mp[nums[q[i]]][x-1], mp[nums[q[i]]][x+1]-mp[nums[q[i]]][x]});
                // cout<<i<<" "<<n<<" "<<x<<endl;
            }
        }
        return res;
    }
};