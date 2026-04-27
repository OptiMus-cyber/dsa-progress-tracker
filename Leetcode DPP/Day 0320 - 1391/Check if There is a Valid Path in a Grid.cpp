class Solution {
public:
    vector<vector<pair<int, int>>> del={{{0, 0}, {0, 0}},
                                        {{0, -1}, {0, 1}},
                                        {{1, 0}, {-1, 0}},
                                        {{0, -1}, {1, 0}},
                                        {{0, 1}, {1, 0}},
                                        {{0, -1}, {-1, 0}},
                                        {{0, 1}, {-1, 0}},
                                    };
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=true;
        if(i==(m-1)&&j==(n-1)) return true;
        for(auto u: del[grid[i][j]]) {
            int x=u.first+i;
            int y=u.second+j;
            if(x>=0&&y>=0&&x<m&y<n&&!vis[x][y]) {
                int f=false;
                for(auto l: del[grid[x][y]]) {
                    int a=l.first+x;
                    int b=l.second+y;
                    if(a==i&&b==j){
                        f=true;
                        break;
                    } 
                }
                if(f&&dfs(x, y, grid, vis)) return true;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        return dfs(0, 0, grid, vis);
    }
};