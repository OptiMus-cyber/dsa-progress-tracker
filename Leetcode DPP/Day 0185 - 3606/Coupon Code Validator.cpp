class Solution {
public:
    bool alpha(string s) {
        for(int i=0; i<s.size(); i++) {
            if(!((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||s[i]=='_')) return false;
        }
        return true;
    }
    bool line(string s) {
        if(s=="electronics"||s=="grocery"||s=="pharmacy"||s=="restaurant") return true;
        return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> arr;
        for(int i=0; i<isActive.size(); i++) 
            if(isActive[i]&&code[i]!="")
                arr.push_back({businessLine[i], code[i]});
        sort(arr.begin(), arr.end());
        vector<string> res;
        for(int i=0; i<arr.size(); i++) 
            if(alpha(arr[i].second)&&line(arr[i].first))
                res.push_back(arr[i].second);
        return res;
    }
};