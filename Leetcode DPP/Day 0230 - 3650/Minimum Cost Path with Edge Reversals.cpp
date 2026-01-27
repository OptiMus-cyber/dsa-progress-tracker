class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], 2*edges[i][2]});
        }
        vector<int> res(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        res[0]=0;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto top=pq.top();
            pq.pop();
            if(res[top.second]<top.first) continue;
            for(auto u: adj[top.second]) {
                if(res[u[0]]>(u[1]+top.first)) {
                    res[u[0]]=(u[1]+top.first);
                    pq.push({res[u[0]], u[0]});
                }
            }
        }
        if(res[n-1]==INT_MAX) return -1;
        return res[n-1];
    }
};