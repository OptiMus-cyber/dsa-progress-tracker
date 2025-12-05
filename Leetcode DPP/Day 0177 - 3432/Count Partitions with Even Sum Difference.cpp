class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0, sum1=0, cnt=0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
        }
        for(int i=0; i<nums.size()-1; i++) {
            if((sum-sum1)%2==0) cnt++;
            sum-=nums[i];
            sum1+=nums[i];
        }
        return cnt;
    }
};