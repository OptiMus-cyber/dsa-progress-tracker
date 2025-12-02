class Solution {
public:
    int mod=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        long long res=0, n=points.size(), c=0;
        for(int i=0; i<points.size(); i++) {
            c+=mp[points[i][1]];
            mp[points[i][1]]++;
        }
        for(auto m: mp) {
            long long sum=(1ll*(m.second-1)*m.second)/2;
            res=(res+(c-sum)*sum)%mod;
            c-=sum;
        }
        return res;
    }
};