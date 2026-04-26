class Solution {
public:
    bool dfs(int i, int j, int a, int b, vector<vector<char>>& grid, vector<vector<int>> &vis, vector<vector<int>> &dfsVis, vector<pair<int, int>> &del) {
        // cout<<i<<" "<<j<<endl;
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=true;
        dfsVis[i][j]=true;
        for(auto u: del) {
            int x=u.first+i;
            int y=u.second+j;
            if(x>=0&&y>=0&&x<m&&y<n&&grid[i][j]==grid[x][y]) {
                if(!vis[x][y]) {
                    // cout<<"x: "<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
                    if(dfs(x, y, i, j, grid, vis, dfsVis, del)) return true;
                } else if(!(x==a&&y==b)&&dfsVis[x][y]) return true;
            } 
        }
        dfsVis[i][j]=false;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)), dfsVis(m, vector<int>(n, 0));
        vector<pair<int, int>> del={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j]) if(dfs(i, j, -1, -1, grid, vis, dfsVis, del)) return true;
            }
        }
        return false;
    }
};