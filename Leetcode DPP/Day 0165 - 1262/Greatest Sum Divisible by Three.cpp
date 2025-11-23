class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> a, b;
        int sum=0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            if(nums[i]%3==1) {
                if(a.size()<2) {
                    a.push_back(i);
                } 
            }
            if(nums[i]%3==2) {
                if(b.size()<2) {
                    b.push_back(i);
                } 
            }
        }
        // cout<<sum<<endl;
        if(sum%3==1) {
            int mini=INT_MAX;
            if(b.size()==2) {
                mini=min(mini, nums[b[0]]+nums[b[1]]);
            }
            if(a.size()) {
                mini=min(mini, nums[a[0]]);
            }
            return sum-mini;
        } else if(sum%3==2) {
            int mini=INT_MAX;
            if(a.size()==2) {
                mini=min(mini, nums[a[0]]+nums[a[1]]);
            }
            if(b.size()) {
                mini=min(mini, nums[b[0]]);
            }
            return sum-mini;
        }
        return sum;
    }
};