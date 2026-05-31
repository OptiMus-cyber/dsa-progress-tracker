class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& ast) {
        long long mass=m;
        sort(ast.begin(), ast.end());
        for(int i=0; i<ast.size(); i++) {
                if(ast[i]<=mass) mass+=ast[i];
                else return false;
        }
        return true;
    }
};