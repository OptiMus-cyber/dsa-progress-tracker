class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> a(26, 0), b(26, 0), c(26, 0), d(26, 0);
        for(int i=0; i<word.size(); i++) {
            if(word[i]>='a'&&word[i]<='z') {
                a[word[i]-'a']=1;
                if(b[word[i]-'a']) {
                    c[word[i]-'a']=0;
                    d[word[i]-'a']=1;
                }
            }
            if(word[i]>='A'&&word[i]<='Z') {
                b[word[i]-'A']=1;
                if(a[word[i]-'A']&&(d[word[i]-'A']==0)) c[word[i]-'A']=1;
            }
        }
        int cnt=0;
        for(int i=0; i<c.size(); i++) cnt+=c[i];
        return cnt;
    }
};