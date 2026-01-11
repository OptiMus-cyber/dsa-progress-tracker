class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int res=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]=='1') {
                    if(i>0) grid[i][j]=grid[i-1][j]+1;
                    else grid[i][j]=1;
                    int k=j, h=grid[i][k];
                    while(k>=0&&mat[i][k]=='1') {
                        h=min(h, grid[i][k]);
                        res=max(res, h*(j-k+1));
                        k--;
                    }
                }
            }
        }
        return res;
    }
};