class Solution {
public:
    int concatenatedBinary(int n) {
        long long res=0;
        int mod=1e9+7, x, i, ns;
        for(i=1; i<=n; i++) {
            x=i, ns=0;
            while(x) {
                ns++;
                x=x>>1;
            }
            res=((res<<ns)|i)%mod;
        }
        return res;
    }
};