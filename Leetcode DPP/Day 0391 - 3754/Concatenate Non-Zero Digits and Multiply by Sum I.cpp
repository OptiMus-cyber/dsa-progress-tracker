class Solution {
public:
    long long sumAndMultiply(int n) {
        int s=0, x=0, a=1;
        int nn=n;
        while(nn) {
            s+=nn%10;
            nn/=10;
        }
        while(n) {
            if(n%10){
                x=x+a*(n%10);
                a*=10;
            }
            n/=10;
        }
        return 1ll*x*s;
    }
};