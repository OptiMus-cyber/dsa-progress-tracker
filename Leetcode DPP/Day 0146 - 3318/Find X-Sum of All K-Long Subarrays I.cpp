class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
            if(i>=k-1) {
                pq={};
                for(auto m: mp) {
                    pq.push({m.second, m.first});
                    if(pq.size()>x) pq.pop();
                }
                int sum=0;
                while(!pq.empty()) {
                    sum+=(pq.top().first*pq.top().second);
                    pq.pop();
                }
                res.push_back(sum);
                mp[nums[i-k+1]]--;
            }
        }
        return res;
    }
};