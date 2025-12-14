class Solution {
public:
    int numberOfWays(string cor) {
        long long s=0, p=0, res=0, mod=1e9+7;
        for(int i=0; i<cor.size(); i++) {
            if(s==2) {
                if(cor[i]=='P') p++;
                else {
                    if(res==0) {
                        res=p+1;
                    } else {
                        res=(res*(p+1))%mod;
                    }
                    s=1;
                    p=0;
                }
            } else {
                if(cor[i]=='S') s++;
            }
        }
        if(s==0) return res;
        if(s==2) return res?res:1;
        return 0; 
    }
};