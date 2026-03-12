class disjoint {
    public:
        vector<int> par, rank;
        disjoint(int &n) {
            rank=vector<int> (n, -1);
            for(int i=0; i<n; i++) par.push_back(i);
        }

        int fpar(int node) {
            if(node == par[node]) return node;
            return par[node]=fpar(par[node]);
        }

        bool uni(int &u, int &v) {
            int pu=fpar(u);
            int pv=fpar(v);
            if(pu==pv) return false;
            if(rank[pu]>rank[pv]) {
                par[pv]=pu;
            } else if(rank[pv]>rank[pu]) {
                par[pu]=pv;
            } else {
                rank[pv]++;
                par[pu]=pv;
            }
            return true;
        }
};
class Solution {
public:
    bool dfs(int i, int j, vector<vector<vector<int>>> &adj, vector<int> &vis) {
        vis[i]=1;
        for(auto u: adj[i]) {
            if(!vis[u[0]]) {
                if(dfs(u[0], i, adj, vis)) return true;
            } else if(u[0]!=j) {
                return true;
            }
        }
        return false;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // vector<vector<vector<int>>> adj(n), adj2(n);
        // vector<int> vis(n, 0), vis2(n, 0);
        vector<int> ans;
        int res=INT_MAX;
        // set<int> st;
        disjoint d(n);
        priority_queue<vector<int>> pq2;
        for(int i=0; i<edges.size(); i++) {
            if(edges[i][3]==1) {
                res=min(res, edges[i][2]);
                // ans.push_back(edges[i][2]);
                // vis[edges[i][0]]=1;
                // vis[edges[i][1]]=1;
                // adj2[edges[i][0]].push_back({edges[i][1]});
                // adj2[edges[i][1]].push_back({edges[i][0]});
                if(!d.uni(edges[i][0], edges[i][1])) return -1;
            
                // st.insert(edges[i][0]);
                // st.insert(edges[i][1]);
            } else {
                pq2.push({edges[i][2], edges[i][1], edges[i][0]});
            }
            // adj[edges[i][0]].push_back({edges[i][1], 2*edges[i][2], edges[i][3]});
            // adj[edges[i][1]].push_back({edges[i][0], 2*edges[i][2], edges[i][3]});
        }
        // for(int i=0; i<n; i++) {
        //     if(!vis2[i]) {
        //         if(dfs(i, -1, adj2, vis2)) {
        //             return -1;
        //         }
        //     }
        // }
        // if(st.empty()) {
        //     st.insert(0);
        //     vis[0]=1;
        // }
        // for(int i: st) {
        //     for(auto u: adj[i]) {
        //         if(!vis[u[0]]) {
        //             pq.push({u[1], u[0], u[2]});
        //         }
        //     }
        // }
        while(!pq2.empty()) {
            auto top=pq2.top();
            pq2.pop();
            if(d.uni(top[1], top[2])) {
                // vis[top[1]]=1;
                // vis[top[2]]=1;
                ans.push_back(top[0]);
                // if(k) {
                //     res=min(res, top[0]);
                //     k--;
                // } else {
                //     res=min(res, top[0]/2);
                // }
            }
        }
        for(int i=0; i<k&&i<ans.size(); i++) ans[ans.size()-1-i]*=2;
        // while(!pq.empty()) {
        //     auto top=pq.top();
        //     pq.pop();
        //     if(!vis[top[1]]) {
        //         vis[top[1]]=true;
        //         if(k) {
        //             res=min(res, top[0]);
        //             k--;
        //         } else {
        //             res=min(res, top[0]/2);
        //         }
        //         for(auto u: adj[top[1]]) {
        //             if(!vis[u[0]]) {
        //                 pq.push({u[1], u[0], u[2]});
        //             }
        //         }
        //     }
        // }
        int par=d.fpar(0);
        for(int i=0; i<n; i++) if(d.fpar(i)!=par) return -1;
        if(ans.size()) res=min(res, *min_element(ans.begin(), ans.end()));
        return res;
    }
};