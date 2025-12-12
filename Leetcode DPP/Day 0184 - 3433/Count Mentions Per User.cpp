class Solution {
public:
    static bool comp(vector<string> &a, vector<string> &b) {
        if(a[1]!=b[1]) return stoi(a[1])<stoi(b[1]);
        return a[0]>b[0];
    }
    vector<int> countMentions(int n, vector<vector<string>>& event) {
        vector<int> res(n, 0);
        vector<int> online(n, 0);
        int all=0;
        sort(event.begin(), event.end(), comp);
        for(int i=0; i<event.size(); i++) {
            if(event[i][0]=="MESSAGE") {
                if(event[i][2]=="ALL") all++;
                else if(event[i][2]=="HERE") {
                    int limit=stoi(event[i][1]);
                    for(int j=0; j<n; j++) {
                        if(online[j]<=limit) {
                            res[j]++;
                        }
                    }
                } else {
                    string s="";
                    for(int j=0; j<event[i][2].size(); j++) {
                        if(event[i][2][j]==' '||j==event[i][2].size()-1) {
                            s+=event[i][2][j];
                            res[stoi(s)]++;
                            s="";
                        } else if(event[i][2][j]>='0'&&event[i][2][j]<='9') {
                            s+=event[i][2][j];
                        }
                    }
                }
            } else {
                online[stoi(event[i][2])]=stoi(event[i][1])+60;
            }
        }
        for(int i=0; i<n; i++) res[i]+=all;
        return res;
    }
};