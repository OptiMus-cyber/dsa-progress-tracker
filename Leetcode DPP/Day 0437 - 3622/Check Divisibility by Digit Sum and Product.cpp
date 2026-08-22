class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0, p=1, nn=n;
        while(nn) {
            s+=nn%10;
            p*=nn%10;
            nn/=10;
        }
        return !(n%(s+p));
    }
};