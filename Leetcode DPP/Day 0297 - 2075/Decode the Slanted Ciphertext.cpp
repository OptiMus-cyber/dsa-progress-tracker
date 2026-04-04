class Solution {
public:
    string decodeCiphertext(string t, int m) {
        int n=t.size()/m;
        vector<vector<char>> mat(m, vector<char>(n, ' '));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mat[i][j]=t[n*i+j];
                // cout<<mat[i][j]<<" ";
            }
            // cout<<endl;
        }
        string ans="", curr="";
        for(int j=0; j<n; j++) {
            for(int i=0; i<m&&(i+j)<n; i++) {
                curr+=mat[i][j+i];
                if(mat[i][j+i]!=' ') {
                    ans+=curr;
                    curr="";
                }
            }
        }
        return ans;
    }
};