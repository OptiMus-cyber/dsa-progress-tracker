class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;
        for(int i=0; i<arr.size(); i++) {
            st.insert(arr[i]);
        }
        int x=1;
        unordered_map<int, int> mp;
        for(auto i: st) {
            mp[i]=x;
            x++;
        }
        vector<int> ans;
        for(int i=0; i<arr.size(); i++) {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};