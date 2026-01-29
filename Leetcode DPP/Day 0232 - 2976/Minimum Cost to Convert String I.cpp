class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> res(26, vector<int> (26, INT_MAX));
        for(int i=0; i<26; i++) res[i][i]=0;
        for(int i=0; i<cost.size(); i++) {
            res[original[i]-'a'][changed[i]-'a']=min(res[original[i]-'a'][changed[i]-'a'], cost[i]);
        }
        for(int k=0; k<26; k++) {
            for(int i=0; i<26; i++) {
                for(int j=0; j<26; j++) {
                    if(res[i][k]!=INT_MAX&&res[k][j]!=INT_MAX)res[i][j]=min(res[i][j], res[i][k]+res[k][j]);
                }
            }
        }
        long long tot=0;
        for(int i=0; i<source.size(); i++) {
            if(res[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
            tot+=res[source[i]-'a'][target[i]-'a'];
        }
        return tot;
    }
};