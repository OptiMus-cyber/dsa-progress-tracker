class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int, int> mp;
        mp[2]=mp[5]=mp[6]=mp[9]=2;
        mp[0]=mp[1]=mp[8]=1;
        mp[3]=mp[4]=mp[7]=0;
        int c=0;
        for(int i=1; i<=n; i++) {
            int f=1, x=i;
            while(x) {
                if(mp[x%10]==2) {
                    f=2;
                }
                if(mp[x%10]==0) {
                    f=0;
                    break;
                }
                x/=10;
            }
            if(f==2) {
                c++;
            }
        }
        return c;
    }
};