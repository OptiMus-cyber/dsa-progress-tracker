class Solution {
public:
    void solve(int i, int &n, string &curr, string &s, unordered_map<string, int> &mp) {
        if(s!="") return ;
        if(i==n) {
            if(!mp.count(curr)) {
                s=curr;
            }
            return;
        }
        curr[i]='1';
        solve(i+1, n, curr, s, mp);
        curr[i]='0';
        solve(i+1, n, curr, s, mp);
        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        int n=nums[0].size();
        string s, curr(n, '0');
        solve(0, n, curr, s, mp);
        return s;
    }
};