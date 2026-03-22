class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        int m=mat.size();
        int n=mat[0].size();
        int f=true, f1=true, f2=true, f3=true;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]!=tar[i][j]) {
                    f=false;
                }
                if(mat[i][j]!=tar[m-i-1][n-j-1]) {
                    f1=false;
                }
                if(mat[i][j]!=tar[j][n-1-i]) {
                    f2=false;
                }
                if(mat[i][j]!=tar[m-1-j][i]) {
                    f3=false;
                }
            }
        }
        return f||f1||f2||f3;
    }
};