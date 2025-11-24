class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int chk = 0;
        for(int i =0; i<nums.size(); i++) {
            chk*=2;
            chk+=nums[i];
            res.push_back((chk%5==0));
            chk%=10;
        }
        return res;
    }
};