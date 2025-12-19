class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[2]<b[2];
    }
    void dfs(int i, unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &res) {
        vis[i]=true;
        res.push_back(i);
        for(auto u: adj[i]) {
            if(!vis[u]) {
                dfs(u, adj, vis, res);
            }
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), comp);
        int time=-1;
        unordered_map<int, vector<int>> adj;
        vector<int> vis(n, false);
        vector<int> res;
        res.push_back(0);
        res.push_back(firstPerson);
        vis[0]=true;
        vis[firstPerson]=true;
        for(int i=0; i<meetings.size(); i++) {
            if(time!=meetings[i][2]) {
                time=meetings[i][2];
                adj.clear();
            }
            if(vis[meetings[i][0]]&&vis[meetings[i][1]]) continue;
            else if(vis[meetings[i][0]]||vis[meetings[i][1]]) {
                if(!vis[meetings[i][0]]) dfs(meetings[i][0], adj, vis, res);
                if(!vis[meeatings[i][1]]) dfs(meetings[i][1], adj, vis, res);
            } else {
                adj[meetings[i][0]].push_back(meetings[i][1]);
                adj[meetings[i][1]].push_back(meetings[i][0]);
            }
        }
        return res;
    }
};