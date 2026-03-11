class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int res=0;
        string s="";
        while(n) {
            s+=((n&1)?'0':'1');
            n=n>>1;
        }
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++) {
            // cout<<s[i]<<" ";
            res=(res<<1)+(s[i]-'0');
        }
        return res;
    }
};