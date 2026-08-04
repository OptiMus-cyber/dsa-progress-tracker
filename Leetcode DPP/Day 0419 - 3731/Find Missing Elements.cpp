class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x=nums.back()-nums[0]+1-nums.size();
        vector<int> res;
        int j=0;
        for(int i=nums[0]; i<=nums.back()&&x; i++) {
            if(nums[j]!=i) {
                res.push_back(i);
                x--;
            } else
            j++;
        }
        return res;
    }
};