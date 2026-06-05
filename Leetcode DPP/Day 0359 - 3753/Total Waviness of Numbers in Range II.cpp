typedef long long ll;
    string str;
    ll dp[20][2][2][11][11][20][20];
    bool done[20][2][2][11][11][20][20];
class Solution {
public:
    ll check(int i, int t, int s, int p1, int p2, int w, int l) {
        if(i==str.size()) {
            if(l<3) return 0;
            return w;
        }
        ll res=dp[i][t][s][p1][p2][w][l];
        if(done[i][t][s][p1][p2][w][l]) return res;
        done[i][t][s][p1][p2][w][l]=true;
        res=0;
        int range=t?(str[i]-'0'):9;
        for(int j=0; j<=range; j++) {
            int nt=(t&&j==range);
            int ns=s|(j!=0);
            int np1=p1, np2=p2;
            int nw=w, nl=l;
            if(!ns) {
                res+=check(i+1, nt, ns, 10, 10, nw, 0);
            } else {
                if(nl>=2) {
                    if(p2!=10&&p1!=10) {
                        if(p1>p2 && p1>j) {
                            nw++;
                        } else if(p1<p2&&p1<j) {
                            nw++;
                        }
                    }
                }
                nl++;
                np2=p1;
                np1=j;
                res+=check(i+1, nt, ns, np1, np2, nw, nl);
            }
        }
        return dp[i][t][s][p1][p2][w][l]=res;
    }
    long long calc(long long n) {
        if(n<100) return 0;
        str=to_string(n);
        memset(done, 0, sizeof(done));
        return check(0,1,0,10, 10, 0, 0);
    }
    long long totalWaviness(long long num1, long long num2) {
        return calc(num2)-calc(num1-1);
    }
};