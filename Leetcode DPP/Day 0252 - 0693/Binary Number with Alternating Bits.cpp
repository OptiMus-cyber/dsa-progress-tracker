class Solution {
public:
    bool hasAlternatingBits(int n) {
        int s=n&1;
        n=n>>1;
        while(n) {
            if(s==(n&1)) {
                return false;
            }
            s=n&1;
            n=n>>1;
        }
        return true;
    }
};