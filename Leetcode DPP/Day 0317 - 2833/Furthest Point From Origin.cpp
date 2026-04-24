class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt=0, x=0;
        for(int i=0; i<moves.size(); i++) {
            if(moves[i]=='_') x++;
            else if(moves[i]=='L') cnt--;
            else cnt++;
        }
        return abs(cnt)+x;
    }
};