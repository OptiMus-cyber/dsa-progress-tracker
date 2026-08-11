class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s=nums[0], f=1;
        vector<int> arr(51, 0);
        arr[nums[0]]++;
        for(int i=1; i<nums.size(); i++) {
            if(f&&nums[i]==nums[i-1]+1) s+=nums[i];
            else f=0;
            arr[nums[i]]++;
        }
        while(s<=50&&arr[s]) {
            s++;
        }
        return s;
    }
};