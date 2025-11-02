class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<guards.size(); i++) vis[guards[i][0]][guards[i][1]]=1;
        for(int i=0; i<walls.size(); i++) vis[walls[i][0]][walls[i][1]]=2;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(vis[i][j]==1) {
                    for(int k=i+1; k<m&&(vis[k][j]==0||vis[k][j]==3); k++) vis[k][j]=3;
                    for(int k=i-1; k>=0&&(vis[k][j]==0||vis[k][j]==3); k--) vis[k][j]=3;
                    for(int k=j+1; k<n&&(vis[i][k]==0||vis[i][k]==3); k++) vis[i][k]=3;
                    for(int k=j-1; k>=0&&(vis[i][k]==0||vis[i][k]==3); k--) vis[i][k]=3;
                }
            }
        }
        int res=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(vis[i][j]==0)
                    res++;
            }
            cout<<endl;
        }
        return res;
    }
};