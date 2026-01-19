class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int t) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<pair<long long, long long>>> sm(m, vector<pair<long long, long long>>(n, {0, 0}));
        long long tot=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i<min(m, n)&&j<min(m, n)) tot+=1ll*mat[i][j];
                if(j>0) sm[i][j].first=1ll*sm[i][j-1].first+1ll*mat[i][j];
                else sm[i][j].first=mat[i][j];
                if(i>0) sm[i][j].second=1ll*sm[i-1][j].second+1ll*mat[i][j];
                else sm[i][j].second=mat[i][j];
            }
        }
        long long temp=-1, rTemp, mini=min(m, n);
        cout<<n<<" "<<m<<endl;
        for(int l=mini; l>=1; l--) {
            temp=tot;
            rTemp=tot;
            for(int i=0; i<m-l+1; i++) {
                if(i!=0) {
                    temp=rTemp+sm[l-1+i][l-1].first-sm[i-1][l-1].first;
                    rTemp=temp;
                }
                for(int j=0; j<n-l+1; j++) {
                    if(j!=0) temp=temp+(sm[l-1+i][l-1+j].second-sm[i][j+l-1].second+mat[i][j+l-1])-(sm[l-1+i][j-1].second-sm[i][j-1].second+mat[i][j-1]);
                    if(temp<=t) {
                        return l;
                    }
                }
            }
            tot=tot-(sm[l-1][l-1].first+sm[l-1][l-1].second-mat[l-1][l-1]);
        }
        return 0;
    }
};