class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        h.push_back(m);
        v.push_back(n);
        unordered_map<int, int> mp;
        for(int i=0; i<h.size(); i++) {
            mp[h[i]-1]++;
            for(int j=i+1; j<h.size(); j++) {
                mp[h[j]-h[i]]++;
            }
        }
        int res=-1, mod =1e9+7;
        for(int i=0; i<v.size(); i++) {
            if(mp.count(v[i]-1)) res=max(res, (v[i]-1));
            for(int j=i+1; j<v.size(); j++) {
                if(mp.count(v[j]-v[i])) res=max(res, v[j]-v[i]);
            }
        }
        if(res==-1) return -1;
        return (1ll*res*res)%mod;
    }
};