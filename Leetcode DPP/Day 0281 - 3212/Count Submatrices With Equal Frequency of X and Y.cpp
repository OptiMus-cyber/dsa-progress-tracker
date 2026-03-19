class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<int, int>>> adj(m, vector<pair<int, int>>(n, {0, 0}));
        int cnt=0;
        for(int i=0; i<m; i++) {
            pair<int, int> arr={0, 0};
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='X') {
                    adj[i][j].first++;
                } else if(grid[i][j]=='Y') {
                    adj[i][j].second++;
                }
                if(i) {
                    adj[i][j].first+=adj[i-1][j].first;
                    adj[i][j].second+=adj[i-1][j].second;
                }
                arr.first+=adj[i][j].first;
                arr.second+=adj[i][j].second;
                if((arr.first)&&arr.first==arr.second) {
                    cnt++;
                }
                // cout<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
            }
            // adj[i]=arr;
        }
        return cnt;
    }
};