class Solution {
public:
    bool checkOnesSegment(string s) {
        int c=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='1') {
                if(c==1) return false;
            } else c=1;
        }
        return true;
    }
};