class Solution {
public:
    int minNumberOperations(vector<int>& tar) {
        int n=tar.size(), mini=0, res=0;
        bool f=true;
        for(int i=1; i<n; i++) {
            if(tar[i-1]>tar[i]) {
                if(f) {
                    f=false;
                    res+=(tar[i-1]-mini);
                }
            }
            if(tar[i-1]<tar[i]) {
                if(!f) {
                    f=true;
                    mini=tar[i-1];
                }
            }
        }
        if(f) res+=(tar[n-1]-mini);
        return res;
    }
};