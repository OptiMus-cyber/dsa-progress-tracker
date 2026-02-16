class Solution {
public:
    int reverseBits(int n) {
        int ans=0, i=0;
        while(i<32) {
            ans=ans<<1;
            ans=ans|(n&1);
            n=n>>1;
            i++;
        }
        return ans;
    }
};