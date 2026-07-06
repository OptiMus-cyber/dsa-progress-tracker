class Solution {
public:
    static int comp(vector<int> &a, vector<int> &b) {
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>=b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intr) {
        sort(intr.begin(), intr.end(), comp);
        int ans=intr.size(), d=-1;
        for(int i=0; i<intr.size(); i++) {
            if(d>=intr[i][1]) {
                ans--;
            }
            d=max(d, intr[i][1]);
        }
        return ans;
    }
};