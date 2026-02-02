class Solution {
public:
    long long solve(int i, int k, int currD, int dist, vector<int>& nums, vector<vector<long long>> &dp) {
        if(k==0) return 0;
        if(i==nums.size()||currD<0) {
            return LONG_LONG_MAX;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        if(i==0) {
            long long mini=LONG_LONG_MAX;
            for(int j=i+1; j<nums.size()-dist; j++) {
                vector<vector<long long>> dp(nums.size(), vector<long long>(k+1, -1));
                long long pick=solve(j, k-1, dist, dist, nums, dp);
                if(pick!=LONG_LONG_MAX) pick+=nums[0];
                mini=min(mini, pick);
            }
            return mini;
            
        } else {
            long long pick=solve(i+1, k-1, currD-1, dist, nums, dp);
            if(pick!=LONG_LONG_MAX) pick+=nums[i];
            long long notPick=solve(i+1, k, currD-1, dist, nums, dp);
            return dp[i][k]=min(pick, notPick);
        }
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        // vector<vector<long long>> dp(nums.size(), vector<long long>(k+1, -1));
        // return solve(0, k, dist, dist, nums, dp);
        long long int res=LONG_LONG_MAX;
        vector<bool> chk(nums.size(), false);
        priority_queue<pair<long long, long long>> pq1;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq2;
        int ex=0;
        long long sum=0, ans=1e15;
        k--;
        for(int i=1; i<nums.size(); i++) {
            while(!pq1.empty()&&dist<(i-pq1.top().second)) {
                ex--;
                pq1.pop();
            }
            // if(!pq1.empty())cout<<pq1.top().first<<endl;
            while(!pq2.empty()&&pq2.top().second<(i-dist)) {
                pq2.pop();
            }
            pq2.push({nums[i], i});
            while(!pq2.empty()&&pq1.size()<(k+ex)) {
                pq1.push({pq2.top().first, pq2.top().second});
                sum+=pq2.top().first;
                pq2.pop();
                while(!pq2.empty()&&pq2.top().second<(i-dist)) {
                    pq2.pop();
                }
            }
            // cout<<ex<<endl;
            // cout<<pq1.size()<<" "<<pq2.size()<<endl;
            // if(!pq2.empty())cout<<pq2.top().first<<endl;
            while(!pq2.empty()&&(pq1.top().first>pq2.top().first)) {
                sum-=pq1.top().first;
                sum+=pq2.top().first;
                pq1.push({pq2.top().first, pq2.top().second});
                pq2.push({pq1.top().first, pq1.top().second});
                pq1.pop();
                pq2.pop();
                while(!pq1.empty()&&dist<(i-pq1.top().second)) {
                    ex--;
                    pq1.pop();
                }
                while(!pq2.empty()&&pq2.top().second<(i-dist)) {
                    pq2.pop();
                }
            }
            if((i-dist)>=1) {
                if(pq1.size()<(k+ex)) break;
                // cout<<pq1.top().first<<" "<<pq2.top().first<<endl;
                // cout<<pq1.size()<<" "<<pq2.size()<<endl;
                // cout<<ex<<endl;
                ans=min(sum+nums[0], ans);
                // cout<<sum+nums[0]<<endl;
                if(nums[i-dist]<pq1.top().first) {
                    sum-=nums[i-dist];
                    ex++;
                }
                if(nums[i-dist]==pq1.top().first&&pq1.top().second>=(i-dist)) {
                    sum-=nums[i-dist];
                    ex++;
                }
                // cout<<ex<<endl;
            }
        }
        return ans;
    }
};