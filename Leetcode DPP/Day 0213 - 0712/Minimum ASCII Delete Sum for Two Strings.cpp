class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==s1.size()) {
            int res=0;
            for(int k=j;k<s2.size();k++) res+=s2[k];
            return dp[i][j]=res;
        }
        if(j==s2.size()) {
            int res=0;
            for(int k=i;k<s1.size();k++) res+=s1[k];
            return dp[i][j]=res;
        }
        if(s1[i]==s2[j]) {
            return dp[i][j]=solve(i+1, j+1, s1, s2, dp);
        } 
        return dp[i][j]=min(s1[i]+solve(i+1, j, s1, s2, dp), s2[j]+solve(i, j+1, s1, s2, dp));
    }
    int minimumDeleteSum(string s1, string s2) {


        // vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -`));
        // // return solve(0, 0, s1, s2, dp);
        

        // vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        // for(int i=s1.size()-1; i>=0; i--) {
        //     dp[i][s2.size()]=dp[i+1][s2.size()]+s1[i];
        // }
        // for(int i=s2.size()-1; i>=0; i--) {
        //     dp[s1.size()][i]=dp[s1.size()][i+1]+s2[i];
        // }
        // for(int i=s1.size()-1; i>=0; i--) {
        //     for(int j=s2.size()-1; j>=0; j--) {
        //         if(s1[i]==s2[j]) {
        //             dp[i][j]=dp[i+1][j+1];
        //         } else {
        //             dp[i][j]=min(s1[i]+dp[i+1][j], s2[j]+dp[i][j+1]);
        //         }
        //     }
        // }
        // return dp[0][0];

        vector<int> curr(s2.size()+1, 0), prev(s2.size()+1, 0);
        for(int i=s2.size()-1; i>=0; i--) {
            prev[i]=prev[i+1]+s2[i];
        }
        for(int i=s1.size()-1; i>=0; i--) {
            curr[s2.size()]=prev[s2.size()]+s1[i];
            for(int j=s2.size()-1; j>=0; j--) {
                if(s1[i]==s2[j]) {
                    curr[j]=prev[j+1];
                } else {
                    curr[j]=min(s1[i]+prev[j], s2[j]+curr[j+1]);
                }
            }
            prev=curr;
        }
        return curr[0];
    }
};