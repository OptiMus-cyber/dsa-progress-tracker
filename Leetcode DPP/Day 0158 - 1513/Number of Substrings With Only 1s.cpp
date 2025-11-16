class Solution {
public:
    int mod=1e9+7;
    long long calc(long long n) {
        return (1ll*n*(n+1))/2;
    }
    int numSub(string s) {
        long long res=0, curr=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='0') {
                res+=calc(curr);
                curr=0;
            } else curr++;
        }
        res+=calc(curr);
        return res%mod;
    }
};