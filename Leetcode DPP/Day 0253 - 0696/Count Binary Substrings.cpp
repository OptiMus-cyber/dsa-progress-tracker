class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0, curr=0, f=(s[0]=='1')?1:0, res=0;
        for(int i=0; i<s.size(); i++) {
            if(f) {
                if(s[i]=='1') {
                    curr++;
                } else {
                    res+=min(curr, prev);
                    prev=curr;
                    curr=1;
                    f=0;
                }
            } else {
                if(s[i]=='1') {
                    res+=min(curr, prev);
                    prev=curr;
                    curr=1;
                    f=1;
                } else {
                    curr++;
                }
            }
        }
        res+=min(curr, prev);
        return res;
    }
};