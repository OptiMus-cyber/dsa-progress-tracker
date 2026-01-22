class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int c=0, idx, idx2, mini, f;
        for(int i=0; i<nums.size(); i++) {
            f=1;
            mini=INT_MAX;
            idx=-1;
            idx2=-1;
            for(int j=0; j<nums.size()-1; ) {
                if(nums[j]==INT_MIN) {
                    j++;
                    continue;
                }
                int k=j+1;
                for(; k<nums.size(); k++) {
                    if(nums[k]!=INT_MIN) {
                        if((nums[j]+nums[k])<mini) {
                            mini=nums[j]+nums[k];
                            idx=j;
                            idx2=k;
                        }
                        if(nums[j]>nums[k]) f=0;
                        break;
                    }
                }
                j=k;
            }
            if(f) {
                return c;
            } else {
                nums[idx]=nums[idx]+nums[idx2];
                nums[idx2]=INT_MIN;
                c++;
            }
        }
        return c;
        // vector<bool> vis(nums.size(), false);
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // for(int i=0; i<nums.size()-1; i++) {
        //     pq.push({nums[i]+nums[i+1], i, i+1});
        // }
        // int ans=0;
        // while(!pq.empty()) {
        //     while(!pq.empty()&&(vis[pq.top()[1]]||vis[pq.top()[2]])) pq.pop();
        //     if(!pq.empty()) {
        //         if(nums[pq.top()[1]]>nums[pq.top()[2]]) {
        //             vis[pq.top()[1]]=true;
        //             nums[pq.top()[1]]+=nums[pq.top()[2]];
        //             int x=pq.top()[2]+1;
        //             while(x<nums.size()) {
        //                 if(!vis[x]) {
        //                     pq.push({nums[pq.top()[1]]+nums[x], pq.top()[1], x});
        //                     break;
        //                 }
        //                 x++;
        //             }
        //             x=pq.top()[1]-1;
        //             while(x>=0) {
        //                 if(!vis[x]) {
        //                     pq.push({nums[pq.top()[1]]+nums[x], pq.top()[1], x});
        //                     break;
        //                 }
        //                 x--;
        //             }
        //         }
        //         ans++;
        //         pq.pop();
        //     }
        // }
        // return ans;
    }
};