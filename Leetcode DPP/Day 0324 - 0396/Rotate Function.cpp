class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxi=0, sum=0;
        for(int i=0; i<nums.size(); i++) {
            maxi+=i*nums[i];
            sum+=nums[i];
        }
        int last=maxi, n=nums.size();
        for(int i=0; i<nums.size(); i++) {
            maxi=max(maxi, last+sum-n*nums[n-i-1]);
            last=last+sum-n*nums[n-i-1];
        }
        return maxi;
    }
};