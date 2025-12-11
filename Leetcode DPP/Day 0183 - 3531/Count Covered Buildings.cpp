class Solution {
public:
    long long int mask(int x, int y) {
        return ((long long) ((long long)x<<20))|(long long)y;
    }
    static bool comp(vector<int> a, vector<int> b) {
        if(a[1]!=b[1])return a[1]<b[1];
        return a[0]<b[0];
    }
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        // sort(b.begin(), b.end());
        // unordered_map<long long, int> mp;
        // for(int i=1; i<b.size()-1; i++) {
        //     if((b[i][0]==b[i-1][0])&&(b[i+1][0]==b[i][0])) mp[mask(b[i][0], b[i][1])]++;
        // }
        // sort(b.begin(), b.end(), comp);
        // for(int i=1; i<b.size()-1; i++) {
        //     if((b[i][1]==b[i-1][1])&&(b[i+1][1]==b[i][1])&&mp.count(mask(b[i][0], b[i][1]))) mp[mask(b[i][0], b[i][1])]++;
        // }
        // int cnt=0;
        // for(auto m: mp) {
        //     if(m.second==2) cnt++;
        // }
        // return cnt;

        vector<pair<int, int>> r(n+1, {-1, -1}), c(n+1, {-1, -1});
        int cnt=0;
        for(int i=0; i<b.size(); i++) {
            if(r[b[i][0]].first!=-1) {
                r[b[i][0]]={min(r[b[i][0]].first, b[i][1]), max(r[b[i][0]].second, b[i][1])};
            } else r[b[i][0]]={b[i][1], b[i][1]};
            if(c[b[i][1]].first!=-1) {
                c[b[i][1]]={min(c[b[i][1]].first, b[i][0]), max(c[b[i][1]].second, b[i][0])};
            } else c[b[i][1]]={b[i][0], b[i][0]};
        }
        for(int i=0; i<b.size(); i++) 
            if(r[b[i][0]].first!=-1&&r[b[i][0]].first<b[i][1]&&r[b[i][0]].second>b[i][1]) {
                if(c[b[i][1]].first!=-1&&c[b[i][1]].first<b[i][0]&&c[b[i][1]].second>b[i][0]) {
                    cnt++;
                }
            }
        return cnt;
    }
};