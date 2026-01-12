class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& pts) {
        int res=0, n=pts.size();
        for(int i=1; i<n; i++) 
            res+=(max(abs(pts[i][0]-pts[i-1][0]), abs(pts[i][1]-pts[i-1][1])));
        return res;
    }
};