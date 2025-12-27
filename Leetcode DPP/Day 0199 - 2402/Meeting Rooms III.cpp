class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        sort(meet.begin(), meet.end());
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<int> cnt(n, 0);
        priority_queue<int, vector<int>, greater<int>> rooms;
        for(int i=0; i<n; i++) rooms.push(i);
        for(int i=0; i<meet.size(); i++) {
            while(!pq.empty()&&pq.top().first<=meet[i][0]) {
                rooms.push(pq.top().second);
                pq.pop();
            }
            if(pq.size()<n) {
                pq.push({meet[i][1], rooms.top()});
                cnt[rooms.top()]++;
                rooms.pop();
            } else {
                pair<long long, long long> top=pq.top();
                pq.pop();
                pq.push({top.first+meet[i][1]-meet[i][0], top.second});
                cnt[top.second]++;
            }
        }
        int maxi=*max_element(cnt.begin(), cnt.end());
        for(int i=0; i<cnt.size(); i++) {
            if(cnt[i]==maxi) return i;
        }
        return maxi;
    }
};