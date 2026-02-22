class Solution {
public:
    int binaryGap(int n) {
        int res=0, c=0, l=-1;
        while(n) {
            if(n%2==1) {
                if(l!=-1) res=max(res, c-l);
                l=c;
            }
            n=n>>1;
            c++;
        }
        return res;
    }
};