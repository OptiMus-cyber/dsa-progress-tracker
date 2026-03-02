class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j]==0) arr[i]++;
                else break;
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++) {
            if(arr[i]>=(n-i-1)) continue;
            for(int j=i+1; j<n; j++) {
                if(arr[j]>=(n-i-1)) {
                    cnt+=(j-i);
                    for(int k=j; k>i; k--) swap(arr[k], arr[k-1]);
                    break;
                }
            }
            if(arr[i]<(n-i-1)) return -1;
        }
        return cnt;
    }
};