class Solution {
public:
    int solve(int i, string &s, vector<string>& dic, int k, vector<vector<int>> &dp) {
        if(k==0) return 0;
        if(i==s.size()) return 1;
        cout<<i<<" "<<k<<endl; 
        if(dp[i][k]!=-1) return dp[i][k];
        int res=0;
        for(int j=0; j<dic.size(); j++) {
            if(s.substr(0, i)==dic[j].substr(0, i)) {
                if(s[i]==dic[j][i]) res|=solve(i+1, s, dic, k, dp);
                else {
                    string s2=s;
                    s2[i]=dic[j][i];
                    res|=solve(i+1, s2, dic, k-1, dp);
                }
            }
        }
        return dp[i][k]=res;
    }
    vector<string> twoEditWords(vector<string>& q, vector<string>& dic) {
        vector<string> res;
        for(int i=0; i<q.size(); i++) {
            // vector<vector<int>> dp(q.size()+1, vector<int>(5, -1));
            // if(solve(0, q[i], dictionary, 3, dp)) res.push_back(q[i]);

            for(int j=0; j<dic.size(); j++) {
                int c=0;
                for(int k=0; k<dic[j].size(); k++) {
                    if(c==3) break;
                    if(q[i][k]!=dic[j][k]) c++;
                }
                if(c<=2) {
                    res.push_back(q[i]);
                    break;
                }
            }
        }
        return res;
    }
};