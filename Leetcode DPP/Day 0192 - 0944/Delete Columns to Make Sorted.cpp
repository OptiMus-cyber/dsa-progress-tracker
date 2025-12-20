class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int c=0, m=strs.size(), n=strs[0].size();
        for(int i=0; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(strs[j][i]<strs[j-1][i]) {
                    c++;
                    break;
                }
            }
        }
        return c;
    }
};