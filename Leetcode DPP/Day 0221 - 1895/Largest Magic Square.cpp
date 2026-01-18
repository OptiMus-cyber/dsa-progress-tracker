class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& grid, int l) {
        vector<int> r(l, 0), c(l, 0);
        int d1=0, d2=0;
        for(int a=0; a<l; a++) {
            d1+=grid[i+a][j+a];
            d2+=grid[i+l-a-1][j+a];
            for(int b=0; b<l; b++) {
                r[a]+=grid[i+a][j+b];
                c[b]+=grid[i+a][j+b];
            }
        }
        // cout<<l<<" "<<d1<<" "<<d2<<" "<<*min_element(r.begin(), r.end())<<" "<<*max_element(r.begin(), r.end())<<" "<<*min_element(c.begin(), c.end())<<" "<<*max_element(c.begin(), c.end())<<endl;
        return (d1==d2)&&(d2==*min_element(r.begin(), r.end()))&&(d2==*max_element(r.begin(), r.end()))&&(d2==*min_element(c.begin(), c.end()))&&(d2==*max_element(c.begin(), c.end()));
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=1;
        for(int i=2; i<=min(m, n); i++) {
            for(int j=0; j<m-i+1; j++) {
                for(int k=0; k<n-i+1; k++) {
                    bool f=solve(j, k, grid, i);
                    // cout<<f<<endl;
                    if(f) res=max(res, i);
                    if(res==i) break;
                }
                if(res==i) break;
            }
        }
        return res;
    }
};