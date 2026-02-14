class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tow(2, vector<double>(2, 0.0));
        tow[0][0]=(double)poured;
        for(int i=0; i<=query_row; i++) {
            for(int j=0; j<=i; j++) {
                if(tow[i][j]>1.0) {
                    tow[i+1][j]+=(tow[i][j]-1)/2.0;
                    tow[i+1][j+1]+=(tow[i][j]-1)/2.0;
                    tow[i][j]=1.0;
                }
            }
            tow.push_back(vector<double>(tow.size()+1, 0.0));
        }
        return tow[query_row][query_glass];
    }
};