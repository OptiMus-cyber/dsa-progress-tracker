class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        long long sum=0;
        vector<int> arr;
        priority_queue<int> pq;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((grid[i][j]%x)!=(grid[0][0]%x)) return -1;
                pq.push(grid[i][j]);
                // arr.push_back(grid[i][j]);
                if(pq.size()>((m*n)/2+1)) pq.pop();
            }
        }
        // sort(arr.begin(), arr.end());
        long long avg=pq.top();
        int res=0, res1=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                res+=(abs(grid[i][j]-avg)/x);
            }
        }
        return res;
    }
};