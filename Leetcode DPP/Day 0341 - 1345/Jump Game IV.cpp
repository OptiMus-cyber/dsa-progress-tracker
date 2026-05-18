class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, bool> chk;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        vector<int> vis(arr.size(), 0);
        q.push({0, 0});
        vis[0]=1;
        while(!q.empty()) {
            pair<int, int> top=q.front();
            // cout<<top.first<<" "<<top.second<<endl;
            q.pop();
            if(top.second==arr.size()-1) return top.first;
            if((top.second+1)<arr.size()) {
                if(!vis[top.second+1]) {
                    vis[top.second+1]=1;
                    q.push({top.first+1, top.second+1});
                }
            }
            if((top.second-1)>=0) {
                if(!vis[top.second-1]) {
                    vis[top.second-1]=1;
                    q.push({top.first+1, top.second-1});
                }
            }
            if(chk[arr[top.second]]) continue;
            for(auto i: mp[arr[top.second]]) {
                if(!vis[i]&&i!=top.second) {
                    vis[i]=1;
                    q.push({top.first+1, i});
                }
            }
            chk[arr[top.second]]=true;
        }
        return 0;
    }
};