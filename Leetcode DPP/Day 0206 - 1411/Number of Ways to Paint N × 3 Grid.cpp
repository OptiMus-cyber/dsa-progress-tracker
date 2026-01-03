class Solution {
public:
    long long mod=1e9+7;
    // int solve(int i, int j, vector<vector<int>> &grid) {
    //     int m=grid.size();
    //     if(i==m) return 1;
    //     long long res=0;
    //     if(j==2) {
    //         for(int k=0; k<3; k++) {
    //             if(((i-1)<0||grid[i-1][j]!=k)&&((j-1)<0||grid[i][j-1]!=k)) {
    //                 grid[i][j]=k;
    //                 res+=solve(i+1, 0, grid);
    //                 grid[i][j]=-1;
    //             }
    //         }
    //     } else {
    //         for(int k=0; k<3; k++) {
    //             if(((i-1)<0||grid[i-1][j]!=k)&&((j-1)<0||grid[i][j-1]!=k)) {
    //                 grid[i][j]=k;
    //                 res+=solve(i, j+1, grid);
    //                 grid[i][j]=-1;
    //             }
    //         }
    //     }
    //     return res%mod;
    // }
    void add(int i, vector<int> &curr, vector<vector<int>> &poss, map<vector<int>, int> &mp) {
        if(i==3) {
            mp[curr]=poss.size();
            poss.push_back(curr);
            return;
        }
        for(int j=0; j<3; j++) {
            if(i>0) {
                if(curr[i-1]!=j) {
                    curr.push_back(j);
                    add(i+1, curr, poss, mp);
                    curr.pop_back();
                }
            } else {
                curr.push_back(j);
                add(i+1, curr, poss, mp);
                curr.pop_back();
            }
        }
    }
    int count(int i, int j, vector<int> &curr, vector<int> &arr, map<vector<int>, int> &mp, vector<vector<int>> &mpp) {
        if(i==3) {
            mpp[mp[arr]][mp[curr]]++;
            return 1;
        }
        int res=0;
        for(int k=0; k<3; k++) {
            if(k!=j&&arr[i]!=k) {
                curr.push_back(k);
                res+=count(i+1, k, curr, arr, mp, mpp);
                curr.pop_back();
            } 
        }
        return res;
    }
    int numOfWays(int n) {
        // vector<vector<int>>grid(n, vector<int>(3, -1));
        // return solve(0, 0, grid);
        map<vector<int>, int> mp;
        vector<vector<int>> poss;
        vector<int> curr;
        add(0, curr, poss, mp);
        if(n==1) return poss.size();
        vector<long long> tot(poss.size(), 0), calc(poss.size(), 0);
        vector<vector<int>> mpp(12, vector<int>(12, 0)), mpp2;
        long long res;
        for(int i=0; i<poss.size(); i++) {
            tot[i]=count(0, -1, curr, poss[i], mp, mpp);
        }
        n--;
        for(int i=0; i<12; i++) {
            for(int j=0; j<12; j++) {
                calc[j]+=mpp[i][j];
            }
        }
        mpp2=mpp;
        while(--n) {
            for(int i=0; i<12; i++) {
                for(int j=0; j<12; j++) {
                    mpp2[i][j]=(mpp[i][j]*calc[i])%mod;
                }
                calc[i]=0;
            }
            for(int i=0; i<12; i++) {
                for(int j=0; j<12; j++) {
                    calc[j]=(calc[j]+mpp2[i][j])%mod;
                }
            }
        }
        res=0;
        for(int i=0; i<12; i++)  res=(res+calc[i])%mod;
        return res;
    }
};