class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int c=0, i=0;
        string s="";
        while(i<a.size()&&i<b.size()) {
            if(c) {
                if(a[i]=='1') {
                    if(b[i]=='1') {
                        c=1;
                        s+='1';
                    } else {
                        c=1;
                        s+='0';
                    }
                } else {
                    if(b[i]=='1') {
                        c=1;
                        s+='0';
                    } else {
                        c=0;
                        s+='1';
                    }
                }
            } else {
                if(a[i]=='1') {
                    if(b[i]=='1') {
                        c=1;
                        s+='0';
                    } else {
                        c=0;
                        s+='1';
                    }
                } else {
                    if(b[i]=='1') {
                        c=0;
                        s+='1';
                    } else {
                        c=0;
                        s+='0';
                    }
                }
            }
            i++;
        }
        while(i<a.size()) {
            if(c) {
               if(a[i]=='1') {
                   s+='0';
               } else {
                   c=0;
                   s+='1';
               }
            } else s+=a[i];
            i++;
        }
        while(i<b.size()) {
            if(c) {
               if(b[i]=='1') {
                   s+='0';
               } else {
                   c=0;
                   s+='1';
               }
            } else s+=b[i];
            i++;
        }
        if(c) s+='1';
        reverse(s.begin(), s.end());
        return s;
    }
};