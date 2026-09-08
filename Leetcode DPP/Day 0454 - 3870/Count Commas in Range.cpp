class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        int c=0, res=0, ten=1, nn=0;
        while(n) {
            nn+=((n%10)*ten);
            c++;
            n/=10;
            ten*=10;
            if(c==3) {
                res+=((c/3)*(nn+1));
                if(n) res+=((c/3)*(n-1)*(ten));
                break;
            }
        }
        return res;
    }
};