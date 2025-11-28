class Solution {
public:
    int solve(int i, vector<vector<int>> &adj, vector<bool> &vis, vector<int>& val, int& res, int& k) {
        vis[i]=true;
        int sum=val[i]%k;
        for(int u: adj[i]) {
            if(!vis[u]) {
                int x=solve(u, adj, vis, val, res, k);
                if(x) {
                    sum=(sum+x)%k;
                } else {
                    res++;
                }
            }
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, false);
        int res=0;
        solve(0, adj, vis, values, res, k);
        return res+1;
    }
};