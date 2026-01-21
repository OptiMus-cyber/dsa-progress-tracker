class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        long long p, f, v;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==2) continue;
            p=1;
            f=1;
            v=0;
            while(nums[i]) {
                if(nums[i]%2!=0) v+=p;
                if(nums[i]%2==0&&f) {
                    v-=p/2;
                    f=0;
                }
                nums[i]/=2;
                p*=2;
            }
            if(f) v-=p/2;
            res[i]=v;
        }
        return res;
    }
};