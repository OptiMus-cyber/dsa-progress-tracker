class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int> mp;
        for(int i=0; i<word.size(); i++) {
            mp[word[i]]++;
        }
        vector<int> arr;
        for(auto i: mp) arr.push_back(i.second);
        sort(arr.rbegin(), arr.rend());
        int res=0;
        for(int i=0; i<arr.size(); i++) {
            res+=arr[i]*(((i)/8)+1);
            cout<<arr[i]<<" "<<i<<endl;
        }
        return res;
    }
};