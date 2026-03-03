class Solution {
public:
    void inv(string &s, string &str) {
        str="";
        for(int i=s.size()-1; i>=0; i--) str+=(s[i]=='1')?'0':'1';
    }
    char findKthBit(int n, int k) {
        // string res="0", str="";
        // while(res.size()<k) {
        //     inv(res, str);
        //     res=res+'1'+str;
        // }
        // return res[k-1];
        if(n==1) return '0';
        int l=(1<<n)-1;
        int m=(l+1)/2;
        if(m==k) {
            return '1';
        } else if(k<m) {
            return findKthBit(n-1, k);
        } else {
            char res=findKthBit(n-1, (1<<(n-1))-(k-m));
            return (res=='1')?'0':'1';
        }
    }
};