class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int chk=1, ans=1;
        unordered_map<int, int> mp;
        while(chk<k) {
            chk=chk*10+1;
            ans++;
        }
        while(mp.count(chk)==0) {
            mp[chk]++;
            if(chk%k==0) return ans;
            chk%=k;
            while(chk<k) {
                chk=chk*10+1;
                ans++;
            }
        }
        return -1;
    }
};