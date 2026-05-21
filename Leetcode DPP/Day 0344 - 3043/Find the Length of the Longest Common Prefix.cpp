class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mp;
        string s;
        for(int i=0; i<arr1.size(); i++) {
            s=to_string(arr1[i]);
            for(int j=0; j<s.size(); j++) {
                mp[s.substr(0, j+1)]++;
            }
        }
        int c=0, n;
        for(int i=0; i<arr2.size(); i++) {
            s=to_string(arr2[i]);
            n=s.size();
            for(int j=0; j<s.size(); j++) {
                if(mp.count(s.substr(0, n-j))) {
                    c=max(c, n-j);
                    break;
                }
            }
        }
        return c;
    }
};