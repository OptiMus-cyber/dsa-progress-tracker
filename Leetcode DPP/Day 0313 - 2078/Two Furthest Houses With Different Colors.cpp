class Solution {
public:
    int maxDistance(vector<int>& clr) {
        int a=clr[0], b=clr.back(), n=clr.size();
        int res=0;
        for(int i=0; i<n; i++) {
            if(clr[i]!=a) res=max(res, i);
            if(clr[i]!=b) res=max(res, n-i-1);
        }
        return res;
    }
};