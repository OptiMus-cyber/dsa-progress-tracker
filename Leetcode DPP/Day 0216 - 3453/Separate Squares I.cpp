class Solution {
public:
    double calc(vector<vector<int>>& sq, double y) {
        double area=0.0;
        for(int i=0; i<sq.size(); i++) {
            if((sq[i][1]+sq[i][2])<=y) {
                area+=((double)sq[i][2]*(double)sq[i][2]);
            } else if(sq[i][1]<y) {
                area+=((double)sq[i][2]*(y-sq[i][1]));
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double tar=calc(squares, 2*1e9+1)/2.0, l=INT_MIN, r=INT_MAX, mid, res;
        for (auto &s : squares) {
            l = min(l, (double)s[1]);
            r = max(r, (double)(s[1] + s[2]));
        }
        while((r-l)>0.00001) {
            mid=(r+l)/2;
            res=calc(squares, mid);
            if(res>=tar) {
                r=mid-0.00001;
            } else {
                l=mid+0.00001;
            }
        }
        return l;
    }
};