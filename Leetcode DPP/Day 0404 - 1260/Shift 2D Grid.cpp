class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> temp=grid, res=grid;
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<k; i++) {
            for(int j=n-1; j>0; j--) {
                for(int l=0; l<m; l++) {
                    temp[l][j]=res[l][j-1];
                }
            }
            for(int l=0; l<m-1; l++) {
                temp[l+1][0]=res[l][n-1];
            }
            temp[0][0]=res[m-1][n-1];
            res=temp;
        }
        return res;
    }
};