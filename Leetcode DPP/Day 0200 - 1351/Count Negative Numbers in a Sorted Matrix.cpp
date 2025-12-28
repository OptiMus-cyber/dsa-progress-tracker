class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res=0, m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++) {
            res+=(n-(upper_bound(grid[i].begin(), grid[i].end(), 0, greater<int>())-grid[i].begin()));
        }
        return res;
    }
};