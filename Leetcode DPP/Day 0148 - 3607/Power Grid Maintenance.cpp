class Union {
    public:
    vector<int> parent;
    vector<int> rank;
    Union(int n) {
        for(int i=0; i<n; i++) parent.push_back(i);
        rank=vector<int>(n, -1);
    }
    int par(int node) {
        if(node==parent[node]) return node;
        return parent[node]=par(parent[node]);
    }
    bool uni(int u, int v) {
        int parU=par(u);
        int parV=par(v);
        if(parU==parV) return false;
        if(rank[parU]>rank[parV]) {
            parent[parV]=parU;
        } else if(rank[parU]<rank[parV]) {
            parent[parU]=parV;
        } else {
            parent[parV]=parU;
            rank[parU]++;
        }
        return true;
    }
};

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, unordered_map<int, priority_queue<int, vector<int>, greater<int>>>&mp, vector<int>& batches, int& batch) {
        vis[node]=true;
        batches[node]=batch;
        mp[batch].push(node);
        for(int u: adj[node]) {
            if(!vis[u]) {
                dfs(u, adj, vis, mp, batches, batch);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& conn, vector<vector<int>>& q) {
        // Union and Find
        Union d(c+1);
        for(int i=0; i<conn.size(); i++) {
            d.uni(conn[i][0], conn[i][1]);
        }
        vector<set<int>> cnt(c+1);
        for(int i=1; i<=c; i++) {
            cnt[d.par(i)].insert(i);
        }
        vector<int> res;
        for(int i=0; i<q.size(); i++) {
            if(q[i][0]==1) {
                if(cnt[d.par(q[i][1])].empty()) res.push_back(-1);
                else if(cnt[d.par(q[i][1])].count(q[i][1])) {
                    res.push_back(q[i][1]);
                } else {
                    res.push_back(*cnt[d.par(q[i][1])].begin());
                }
            } else {
                cnt[d.par(q[i][1])].erase(q[i][1]);
            }
        }
        return res;

        // DFS
        // vector<bool> op(c+1, true), vis(c+1, false);
        // vector<int> batches(c+1, -1);
        // vector<vector<int>> adj(c+1);
        // for(int i=0; i<conn.size(); i++) {
        //     adj[conn[i][0]].push_back(conn[i][1]);
        //     adj[conn[i][1]].push_back(conn[i][0]);
        // }
        // unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        // int batch=0;
        // for(int i=1; i<=c; i++) {
        //     if(!vis[i]) {
        //         dfs(i, adj, vis, mp, batches, batch);
        //         batch++;
        //     }
        // }
        // vector<int> res;
        // for(int i=0; i<q.size(); i++) {
        //     if(q[i][0]==1) {
        //         if(op[q[i][1]]) {
        //             res.push_back(q[i][1]);
        //         } else {
        //             while(!mp[batches[q[i][1]]].empty()&&!op[mp[batches[q[i][1]]].top()]) mp[batches[q[i][1]]].pop();
        //             if(mp[batches[q[i][1]]].empty()) res.push_back(-1);
        //             else res.push_back(mp[batches[q[i][1]]].top());
        //         }
        //     } else {
        //         op[q[i][1]]=false;
        //     }
        // }
        // return res;
    }
};