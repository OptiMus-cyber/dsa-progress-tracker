class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mini=INT_MAX;
        vector<vector<int>> res;
        for(int i=0; i<arr.size()-1; i++) {
            if(mini>(arr[i+1]-arr[i])) {
                res.clear();
                mini=arr[i+1]-arr[i];
                res.push_back({arr[i], arr[i+1]});
            } else if(mini==(arr[i+1]-arr[i])) res.push_back({arr[i], arr[i+1]});
        }
        return res;
    }
};