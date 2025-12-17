class Solution {
public:
    long long solve(int i, vector<int>& prices, int k, vector<vector<vector<long long>>> &dp, int state) {
        if(i==prices.size()-1||k==0) {
            if(i==prices.size()-1) {
                if(state==1) return prices[i];
                if(state==2) return -prices[i];
            }
            return 0;
        } 
        if(dp[i][k][state]!=-1) return dp[i][k][state];
        dp[i][k][state]=solve(i+1, prices, k, dp, state);
        if(state!=0) {
            if(state==1) dp[i][k][state]=max(dp[i][k][state], solve(i+1, prices, k-1, dp, 0)+prices[i]);
            if(state==2) dp[i][k][state]=max(dp[i][k][state], solve(i+1, prices, k-1, dp, 0)-prices[i]);
        } else {
            dp[i][k][state]=max(dp[i][k][state], solve(i+1, prices, k, dp, 1)-prices[i]);
            dp[i][k][state]=max(dp[i][k][state], solve(i+1, prices, k, dp, 2)+prices[i]);
        }
        return dp[i][k][state];
    }
    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<vector<long long>>> dp(prices.size(), vector<vector<long long>>(k+1, vector<long long>(3, -1)));
        // for(int i=prices.size()-1; i>=0; i--) {
        //     for(int j=prices.size()-1; j>=-1; j--) {
        //         for(int m=0; m<=k; m++) {
        //             cout<<i<<" "<<j<<" "<<m<<endl;
        //             if(j!=-1) {
        //                 dp[i][j+1][m]=max(dp[i][j+1][m], abs((long long)prices[i]-(long long)prices[j])+dp[i+1][0][m-1]);
        //                 dp[i][j+1][m]=max(dp[i][j+1][m], dp[i+1][j][m]);
        //             } else {
        //                 dp[i][j+1][m]=max(dp[i][j+1][m], dp[i+1][i][m]);
        //                 dp[i][j+1][m]=max(dp[i][j+1][m], dp[i+1][0][m]);
        //             }
        //         }
        //     }
        // }
        return solve(0, prices, k, dp, 0);
        // bool inc=true;
        // long long last=0, res=0;
        // inc=prices[0]<prices[1]?true:false;
        // for(int i=1; i<prices.size(); i++) {
        //     // cout<<inc<<" "<<i<<" "<<res<<endl;
        //     if(inc) {
        //         if(prices[i-1]>=prices[i]) {
        //             res+=prices[i-1]-prices[last];
        //             last=i;
        //             if(i!=prices.size()-1) inc=prices[i]<prices[i+1]?true:false;
        //         }
        //     } else {
        //         if(prices[i-1]<=prices[i]) {
        //             res+=prices[last]-prices[i-1];
        //             last=i;
        //             if(i!=prices.size()-1) inc=prices[i]<prices[i+1]?true:false;
        //         }
        //     }
        // }
        // if(last!=prices.size()-1) res+=abs(prices[prices.size()-1]-prices[last]);
        // return res;
    }
};