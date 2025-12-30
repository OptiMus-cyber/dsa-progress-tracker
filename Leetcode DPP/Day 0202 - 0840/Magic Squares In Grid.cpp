class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& grid) {
        int s1=-1, s2=0, s3=0, s4=0, s5=0;
        vector<int> vis(10, 0);
        for(int i=0; i<3; i++) {
            s2=0, s3=0;
            for(int j=0; j<3; j++) {
                if(grid[x+i][y+j]<1||grid[x+i][y+j]>9||vis[grid[x+i][y+j]]) return false;
                else vis[grid[x+i][y+j]]=1;
                s2+=grid[x+i][y+j];
                s3+=grid[x+j][y+i];
            }
            if(s1==-1) s1=s2;
            if(s1!=s2||s1!=s3) return false;
            s4+=grid[x+i][y+i];
            s5+=grid[x+i][y+2-i];
        }
        if(s1!=s4||s1!=s5) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(), c=0;
        for(int i=0; i<m-2; i++) {
            for(int j=0; j<n-2; j++) {
                if(solve(i, j, grid)) c++;
            }
        }
        return c;
    }
};