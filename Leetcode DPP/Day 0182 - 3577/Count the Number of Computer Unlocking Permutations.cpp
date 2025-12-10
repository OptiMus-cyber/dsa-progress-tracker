class Solution {
public:
    int countPermutations(vector<int>& comp) {
        int mod=1e9+7, n=comp.size();
        long long res=1;
        for(int i=1; i<n; i++) {
            if(comp[i]<=comp[0]) return 0;
            res=(res*i)%mod;
        }
        return res;
    } 
};