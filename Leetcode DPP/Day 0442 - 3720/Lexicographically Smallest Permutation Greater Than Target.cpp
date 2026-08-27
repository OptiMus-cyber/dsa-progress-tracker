class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end());
        if(s.size()<target.size()) return "";
        vector<int> arr(26, 0);
        for(int i=0; i<s.size(); i++) 
            arr[s[i]-'a']++;
        string res=s;
        int idx=target.size();
        for(int i=0; i<target.size(); i++) {
            bool f=false;
            for(int j=target[i]-'a'; j<26; j++) {
                if(arr[j]!=0) {
                    res[i]=j+'a';
                    arr[j]--;
                    f= true;
                    break;
                }
            }
            if(res[i]>target[i]) {
                idx=i+1;
                break;
            }
            if(!f||(i==target.size()-1)) { 
                
                bool fl=false;
                int k=i-1;
                if(f) k=i;
                    // cout<<res<<endl;
                for(; k>=0; k--) {
                    arr[res[k]-'a']++;
                    for(int m=res[k]-'a'+1; m<26; m++) {
                        if(arr[m]!=0) {
                            res[k]=m+'a';
                            fl=true;
                            idx=k+1;
                            arr[m]--;
                            break;
                        }
                    }
                    if(fl) break;
                    // res[k]='*';
                }
                if(!fl) return "";
                break;
            }
        }
        // cout<<res<<" "<<idx<<endl;
        for(int i=0; i<26; i++) {
            while(arr[i]) {
                res[idx]=i+'a';
                arr[i]--;
                idx++;
            }
        }
        if(res==target) {
            return "";
        }
        return res;
    }
};