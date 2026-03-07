class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        if(n%2) {
            // c0 O E O E
            // c1 E O E O
            vector<int> c0(n, 0), c1(n, 0);
            c0[0]=(s[0]=='1')?0:1;
            c1[0]=(s[0]=='1')?1:0;
            for(int i=1; i<n; i++) {
                if(s[i]=='1') {
                    if(i%2==0) {
                        c0[i]=c0[i-1];
                        c1[i]=c1[i-1]+1;
                    } else {
                        c0[i]=c0[i-1]+1;
                        c1[i]=c1[i-1];
                    }
                } else {
                    if(i%2==0) {
                        c0[i]=c0[i-1]+1;
                        c1[i]=c1[i-1];
                    } else {
                        c0[i]=c0[i-1];
                        c1[i]=c1[i-1]+1;
                    }
                }
                // cout<<c0[i-1]<<" "<<c1[i-1]<<endl;
            }
                // cout<<c0.back()<<" "<<c1.back()<<endl;
            int zero=c0.back(), one=c1.back();
            int mini=min(zero, one);
            for(int i=0; i<n; i++) {
                // cout<<zero-c0[i]+c1[i]<<" "<<one-c1[i]+c0[i]<<endl;
                mini=min({mini, zero-c0[i]+c1[i], one-c1[i]+c0[i]});
            }
            return mini;

        } else {
            int c0=0, c1=0;
            for(int i=0; i<n; i++) {
                if(s[i]=='1') {
                    if(i%2==0) c0++;
                    else c1++;
                } else {
                    if(i%2==0) c1++;
                    else c0++;
                }
            }
            return min(c0, c1);
        }
        return 0;
    }
};