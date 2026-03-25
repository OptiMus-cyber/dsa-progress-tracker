class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        unordered_map<double, int> mp;
        long long sum=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                sum+=grid[i][j];
            }
            mp[sum]++;
        }
        if(mp.count((double)sum/(double)2)) return true;
        long long sum2=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                sum2+=grid[j][i];
            }
            mp[sum2]++;
        }
        if(mp.count((double)sum/(double)2)) return true;
        return false;
    }
};