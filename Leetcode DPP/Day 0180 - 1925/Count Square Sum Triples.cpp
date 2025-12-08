class Solution {
public:
    int countTriples(int n) {
        int cnt=0, k;
        for(int i=1; i<=n; i++) {
            if(i*i>n*n) break;
            for (int j=i; j<=n; j++) {
                if((i*i+j*j)>n*n) break;
                k=sqrt(i*i+j*j);
                if(k*k==i*i+j*j) {
                    if(i==j) cnt++;
                    else cnt+=2;
                }
            }
        }
        return cnt;
    }
};