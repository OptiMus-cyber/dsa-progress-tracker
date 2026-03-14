class Solution {
public:
    string s="abc";
    int cnt;
    void solve(int i, int &n, string &curr, vector<string> &res) {
        if(res.size()==cnt) return;
        if(i==n) {
            // cout<<curr<<endl;
            res.push_back(curr);
            return;
        }
        for(auto c: s) {
            if(!i||c!=curr[i-1]) {
                curr[i]=c;
                solve(i+1, n, curr, res);
            }
        }
        return;
    }

    string getHappyString(int n, int k) {
        if((1<<(n-1))*3<k) return "";
        vector<string> res;
        string curr(n, ' ');
        cnt=k;
        solve(0, n, curr, res);
        // sort(res.begin(), res.end());
        return res[k-1];
    }
};