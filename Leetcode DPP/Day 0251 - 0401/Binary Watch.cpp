class Solution {
public:
    void solve(int i, int j, int k, int a, int b, vector<string> &res, vector<int> &hrs, vector<int> &mins) {
        if((i==hrs.size()&&j==mins.size())||k<=0) {
            if(k==0) {
                string s="";
                if(a>=12||b>=60) {
                    return;
                } else {
                    s+=(to_string(a));
                    s+=':';
                    if(b<10) {
                        s+=('0'+to_string(b));
                    } else {
                        s+=(to_string(b));
                    }
                }
                res.push_back(s);
            }
            return;
        } else if(i==hrs.size()) {
            solve(i, j+1, k-1, a, b+mins[j], res, hrs, mins);
            solve(i, j+1, k, a, b, res, hrs, mins);
        } else if(j==mins.size()) {
            solve(i+1, j, k-1, a+hrs[i], b, res, hrs, mins);
            solve(i+1, j, k, a, b, res, hrs, mins);
        } else {
            solve(i+1, j+1, k-2, a+hrs[i], b+mins[j], res, hrs, mins);
            solve(i+1, j+1, k-1, a, b+mins[j], res, hrs, mins);
            solve(i+1, j+1, k-1, a+hrs[i], b, res, hrs, mins);
            solve(i+1, j+1, k, a, b, res, hrs, mins);
        }
        return;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> hrs={1, 2, 4, 8};
        vector<int> mins={1, 2, 4, 8, 16, 32};
        vector<string> res;
        solve(0, 0, turnedOn, 0, 0, res, hrs, mins);
        // sort(res.begin(), res.end());
        return res;
    }
};