class Solution {
public:
    int longestBalanced(string s) {
        vector<int> cnt(26, 0);
        int res=0;
        bool f=true;
        int c=0;
        for(int i=0; i<s.size(); i++) {
            cnt=vector<int>(26, 0);
            if(s.size()-i<=res) break;
            for(int j=i; j<s.size(); j++) {
                cnt[s[j]-'a']++;
                f=true, c=0;
                for(int k=0; k<26; k++) {
                    if(cnt[k]!=0) {
                        if(c==0) c=cnt[k];
                        else if(c!=cnt[k]) {
                            f=false;
                            break;
                        }
                    }
                }
                if(f) res=max(res, j-i+1);
            }
        }
        return res;
    }
};